// Virtual Boy WAV converter by Pat Daderko (DogP) - http://www.projectvb.com
//
// Program based on wavIO by Evan X. Merz, modified to write data to .h file in VB friendly format, added scaling, and a few misc changes
// www.thisisnotalabel.com

// Example Wav file input and output
// this was written for educational purposes, but feel free to use it for anything you like 
// as long as you credit me appropriately ("wav IO based on code by Evan Merz")

// if you catch any bugs in this, or improve upon it significantly, send me the changes
// at evan at thisisnotalabel dot com, so we can share your changes with the world

#include <fstream>
#include <iostream>
using namespace std;


class WavFileForIO
{
/*
     WAV File Specification
     FROM http://ccrma.stanford.edu/courses/422/projects/WaveFormat/
    The canonical WAVE format starts with the RIFF header:
    0         4   ChunkID          Contains the letters "RIFF" in ASCII form
                                   (0x52494646 big-endian form).
    4         4   ChunkSize        36 + SubChunk2Size, or more precisely:
                                   4 + (8 + SubChunk1Size) + (8 + SubChunk2Size)
                                   This is the size of the rest of the chunk 
                                   following this number.  This is the size of the 
                                   entire file in bytes minus 8 bytes for the
                                   two fields not included in this count:
                                   ChunkID and ChunkSize.
    8         4   Format           Contains the letters "WAVE"
                                   (0x57415645 big-endian form).

    The "WAVE" format consists of two subchunks: "fmt " and "data":
    The "fmt " subchunk describes the sound data's format:
    12        4   Subchunk1ID      Contains the letters "fmt "
                                   (0x666d7420 big-endian form).
    16        4   Subchunk1Size    16 for PCM.  This is the size of the
                                   rest of the Subchunk which follows this number.
    20        2   AudioFormat      PCM = 1 (i.e. Linear quantization)
                                   Values other than 1 indicate some 
                                   form of compression.
    22        2   NumChannels      Mono = 1, Stereo = 2, etc.
    24        4   SampleRate       8000, 44100, etc.
    28        4   ByteRate         == SampleRate * NumChannels * BitsPerSample/8
    32        2   BlockAlign       == NumChannels * BitsPerSample/8
                                   The number of bytes for one sample including
                                   all channels. I wonder what happens when
                                   this number isn't an integer?
    34        2   BitsPerSample    8 bits = 8, 16 bits = 16, etc.

    The "data" subchunk contains the size of the data and the actual sound:
    36        4   Subchunk2ID      Contains the letters "data"
                                   (0x64617461 big-endian form).
    40        4   Subchunk2Size    == NumSamples * NumChannels * BitsPerSample/8
                                   This is the number of bytes in the data.
                                   You can also think of this as the size
                                   of the read of the subchunk following this 
                                   number.
    44        *   Data             The actual sound data.
*/


    	private:
		char* 	myPath;
		int 	myChunkSize;
		int	mySubChunk1Size;
		short 	myFormat;
		short 	myChannels;
		int   	mySampleRate;
		int   	myByteRate;
		short 	myBlockAlign;
		short 	myBitsPerSample;
		double scale_factor;
		
	public:
		// I made this public so that you can toss whatever you want in here
		// maybe a recorded buffer, maybe just whatever you want
		char* 	myData;
		int	myDataSize;

		// get/set for the Path property
		char* getPath()
		{
			return myPath;
		}
		void setPath(char* newPath)
		{
			myPath = new char[200];
			strcpy(myPath, newPath);
		}

		~WavFileForIO()
		{
			delete myPath;
			myChunkSize = 0;
			mySubChunk1Size = 0;
 		    myFormat = 0;
			myChannels = 0;
			mySampleRate = 0;
			myByteRate = 0;
			myBlockAlign = 0;
			myBitsPerSample = 0;
			myDataSize = 0;
			scale_factor = 1.0;
		}

	// empty constructor
	WavFileForIO()
        {
		myPath = new char[200];
        }

	// constructor takes a wav path
	WavFileForIO(char* tmpPath)
        {
		myPath = new char[200];
		strcpy(myPath, tmpPath);
		myChunkSize = 0;
		mySubChunk1Size = 0;
	    myFormat = 0;
		myChannels = 0;
		mySampleRate = 0;
		myByteRate = 0;
		myBlockAlign = 0;
		myBitsPerSample = 0;
		myDataSize = 0;
		scale_factor = 1.0;
		read();
        }

	// read a wav file into this class
	bool read()
	{
        char is_data[4];
		ifstream inFile( myPath, ios::in | ios::binary);
		if (inFile.fail())
		{
           inFile.close();
		   return false;
        }

		//printf("Reading wav file...\n"); // for debugging only

		inFile.seekg(4, ios::beg);
		inFile.read( (char*) &myChunkSize, 4 ); // read the ChunkSize

		inFile.seekg(16, ios::beg);
		inFile.read( (char*) &mySubChunk1Size, 4 ); // read the SubChunk1Size

		//inFile.seekg(20, ios::beg);
		inFile.read( (char*) &myFormat, sizeof(short) ); // read the file format.  This should be 1 for PCM

		//inFile.seekg(22, ios::beg);
		inFile.read( (char*) &myChannels, sizeof(short) ); // read the # of channels (1 or 2)

		//inFile.seekg(24, ios::beg);
		inFile.read( (char*) &mySampleRate, sizeof(int) ); // read the samplerate

		//inFile.seekg(28, ios::beg);
		inFile.read( (char*) &myByteRate, sizeof(int) ); // read the byterate

		//inFile.seekg(32, ios::beg);
		inFile.read( (char*) &myBlockAlign, sizeof(short) ); // read the blockalign

		//inFile.seekg(34, ios::beg);
		inFile.read( (char*) &myBitsPerSample, sizeof(short) ); // read the bitspersample

        inFile.seekg(36, ios::beg);
        inFile.read(is_data, 4);
		if (!strncmp(is_data, "data",4)) //make sure "data" is actually here
		    inFile.read( (char*) &myDataSize, sizeof(int) ); // read the size of the data
        else //probably unexpected "fact" field, check to skip
        {
            inFile.seekg(50, ios::beg);
            inFile.read(is_data, 4);
	        if (!strncmp(is_data, "data",4)) //make sure "data" is actually here
   		        inFile.read( (char*) &myDataSize, sizeof(int) ); // read the size of the data
	        else //I dunno, get out
	        {
                myDataSize=0;
                inFile.close();
	            return false;
            }
        }


		// read the data chunk
		myData = new char[myDataSize];
		inFile.read(myData, myDataSize);

		inFile.close(); // close the input file

		return true; // this should probably be something more descriptive
	}

    // scale file to full amplitude
    bool scale()
    {
        int temp, min=65536, max=0, i;
        unsigned char * bytedata;
        short * shortdata;
        if ((myBitsPerSample/8)==1) //8 bit file
        {
            bytedata=(unsigned char*)myData;
            for (i=0; i<myDataSize; i++) //find min and max in data
            {
                 temp=bytedata[i];
                 if (temp>max)
                     max=temp;
                 if (temp<min)
                     min=temp;
            }
            //don't do anything if max = min
            if (min!=max)
            {
                if ((128-min)>=(max-127)) //mag of min larger than max
                    scale_factor=(128.0/((double)(128-min)));
                else
                    scale_factor=(128.0/((double)(max-127)));
            }
            
            //cout << scale_factor << " " << max << " " << min << endl; //debugging
            
            for (i=0; i<myDataSize; i++) //scale data by scale factor
                bytedata[i]=(unsigned char)(((double)(bytedata[i]-128))*scale_factor)+128;
        }
        else //16 bit file
        {
            shortdata=(short*)myData;
            for (i=0; i<(myDataSize/2); i++)
            {
                 temp=abs(shortdata[i]);
                 if (temp>max)
                     max=temp;
                 if (temp<min)
                     min=temp;
            }
            if (min!=max) //scale
                scale_factor=(32767.0/((double)max)); //make max-min as close to 32767 as possible
                
            //cout << scale_factor << " " << max << " " << min << endl; //debugging
            
            for (i=0; i<(myDataSize/2); i++) //scale data by scale factor
                shortdata[i]=(short)(((double)shortdata[i])*scale_factor);
        }
    }
    
	// write out the wav file
	bool save()
	{
		fstream myFile (myPath, ios::out | ios::binary);

		// write the wav file per the wav file format
		myFile.seekp (0, ios::beg); 
		myFile.write ("RIFF", 4);
		myFile.write ((char*) &myChunkSize, 4);
		myFile.write ("WAVE", 4);
		myFile.write ("fmt ", 4);
		myFile.write ((char*) &mySubChunk1Size, 4);
		myFile.write ((char*) &myFormat, 2);
		myFile.write ((char*) &myChannels, 2);
		myFile.write ((char*) &mySampleRate, 4);
		myFile.write ((char*) &myByteRate, 4);
		myFile.write ((char*) &myBlockAlign, 2);
		myFile.write ((char*) &myBitsPerSample, 2);
		myFile.write ("data", 4);
		myFile.write ((char*) &myDataSize, 4);
		myFile.write (myData, myDataSize);

		return true;
	}
	
	// write out the data in header for VB
	bool save_vb()
	{
        int i, which_half=0, outdata=0, name_len;
        char *pch, *last_pch;
        char name[50], capname[50];
        unsigned char * bytedata;
        short * shortdata;
		fstream myFile (myPath, ios::out);

        last_pch=NULL;
        pch=strchr(myPath,'\\');
        while (pch!=NULL)
        {
            last_pch=pch;
            pch=strchr(pch+1,'\\');
        }
        if (last_pch==NULL)
            last_pch=myPath;

        pch=strchr(last_pch, '.');
        if (pch==NULL)
            name_len=strlen(myPath);
        else
            name_len=(int)pch-(int)last_pch;
        
        strncpy(name, last_pch, name_len);
        name[name_len]=0; //null terminate
        
        for (i=0; i<name_len; i++) //make uppercase for #define stuff
            capname[i]=toupper(name[i]);
        capname[name_len]=0; //null terminate

		// write the wav data to the .h file
		myFile.seekp (0, ios::beg); 
		//put file info in header
		myFile << "#define " << capname << "_CH " << myChannels << endl;
		myFile << "#define " << capname << "_SR " << mySampleRate << endl;
		myFile << "#define " << capname << "_LEN " << ((myDataSize/(myBitsPerSample/8))/myChannels) << endl << endl;
		
		myFile << "const unsigned char " << name << "[] = {" << endl;
        if ((myBitsPerSample/8)==1) //8 bit file
        {
            bytedata=(unsigned char*)myData;
            for (i=0; i<myDataSize; i++) //loop through all data
    		{
                //pack two 4 bit values into one byte
                outdata |= (bytedata[i]>>4) << ((which_half^1)*4);
                if (which_half==1)
                {
                    myFile << "0x" << hex << outdata << "," << endl;
                    outdata=0;
                }
                which_half^=1;
            }
            if (which_half==1) //if odd number, flush to file
            {
                myFile << "0x" << hex << outdata << "," << endl;
                outdata=0;
                which_half=0;
            }
            myFile << "};" << endl;
        }
        else //16 bit file
        {
            shortdata=(short*)myData;
            for (i=0; i<(myDataSize/(myBitsPerSample/8)); i++) //loop through all data
    		{
                //pack two 4 bit values into one byte
                outdata |= ((shortdata[i]+32768)/4096) << ((which_half^1)*4);
                if (which_half==1)
                {
                    myFile << "0x" << hex << outdata << "," << endl;
                    outdata=0;
                }
                which_half^=1;
            }
            if (which_half==1) //if odd number, flush to file
            {
                myFile << "0x" << hex << outdata << "," << endl;
                outdata=0;
                which_half=0;
            }
            myFile << "};" << endl;
        }

		return true;
	}

	// return a printable summary of the wav file
	char *getSummary()
	{
		char *summary = new char[250];
		if ((myBitsPerSample!=0)&&(myDataSize!=0)) //prevent div by 0
		    sprintf(summary, " Channels: %d\n SampleRate: %d\n BitsPerSample: %d\n Samples: %d\n Scale: %f", myChannels, mySampleRate, myBitsPerSample, myDataSize/(myBitsPerSample/8), scale_factor);
        else
            sprintf(summary, " No samples or error reading file\n");
		return summary;
	}
};


int main( int argc, char *argv[] )
{
    int scale=0;
	// make sure that an argument was passed in
	if (( argc == 4 ) && (!strcmp(argv[3], "-s")))
        scale=1;
    else if ( argc != 3 )
	{
		cout << "Virtual Boy WAV converter v1.0 by Pat Daderko (DogP) - www.projectvb.com" << endl;
		cout << "WAV IO based on code by Evan Merz" << endl << endl;
        cout << " usage: "<< argv[0] <<" <filename> <outfile> [-s]" << endl;
        cout << " option -s auto-scales file to full amplitude" << endl;
		return 0;
	}

	// open the wav file
	char *path = new char[50];
	strcpy(path, argv[1]);
	WavFileForIO *myWav = new WavFileForIO(path);

    if (scale) //scale file
        myWav->scale();
        
	// print a summary
	char *summary = myWav->getSummary();
	printf("Summary:\n%s", summary);
    
    if (myWav->myDataSize==0) //get out
	{
        delete summary;
        delete path;
        delete myWav;
	    return 1;
    }
	// write the converted file
	strcpy(path, argv[2]);
	myWav->setPath(path);
	myWav->save_vb();

	// collect the garbage
	delete summary;
	delete path;
	delete myWav;

	return 0;
}
