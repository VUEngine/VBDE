#!/bin/bash


NAME=$1
if [ -z "$NAME" ]; then
	NAME="Image"
fi
WORKING_FOLDER=$2
if [ -z "$WORKING_FOLDER" ]; then
	WORKING_FOLDER="."
fi
OUTPUT_FOLDER=$3
if [ -z "$OUTPUT_FOLDER" ]; then
	OUTPUT_FOLDER="."
fi

OUTPUT_FILE=$NAME.cc
FINAL_OUTPUT_FILE=$OUTPUT_FOLDER/$NAME.c
TILES_OUTPUT_FILE=${NAME}Tiles.cc
MAP_OUTPUT_FILE=${NAME}Map.cc

#pre clean
rm -f $FINAL_OUTPUT_FILE

cd $WORKING_FOLDER
FILES=`ls -1v *.c`

biggerTilesArrayFile=0
biggerTilesArray=0
searchString1="Tiles["
searchString2="]"
numberOfFrames=0

#find bigger array
for file in $FILES; do
	line=`grep Tiles $file`
	rest=${line#*$searchString1}
	startPosition=$(( ${#line} - ${#rest} - ${#searchString1} )) 
	rest=${line#*$searchString2}
	endPosition=$(( ${#line} - ${#rest} - ${#searchString2} )) 
	totalTiles=${line:$startPosition+${#searchString1}:endPosition-startPosition-${#searchString1}}
	
	if [ "$totalTiles" -gt "$biggerTilesArray" ]; then

		biggerTilesArray=$totalTiles
		biggerTilesArrayFile=$file
	fi


	numberOfFrames=$((numberOfFrames + 1))
done

rm -f $TILES_OUTPUT_FILE

for file in $FILES; do
	line=`grep Tiles $file`
	rest=${line#*$searchString1}
	startPosition=$(( ${#line} - ${#rest} - ${#searchString1} )) 
	rest=${line#*$searchString2}
	endPosition=$(( ${#line} - ${#rest} - ${#searchString2} )) 
	totalTiles=${line:$startPosition+${#searchString1}:endPosition-startPosition-${#searchString1}}
	let difference=biggerTilesArray-totalTiles
	
	while read line
	do
		if [[ $line == *"};"* ]]; then
			break
		fi

		if [[ $line == *"0x"* ]]; then
			echo $line >> $TILES_OUTPUT_FILE
		fi
		
	done < $file

	while [ "$difference" -gt 0 ]
	do
		echo 0x00000000, >> $TILES_OUTPUT_FILE
		difference=$((difference-1))
	done
done
	
rm -f $MAP_OUTPUT_FILE

for file in $FILES; do

	writingMap=false
	while read line
	do
		if [[ $line == *"};"* ]]; then
		
			if [[ $writingMap == true ]]; then
		
				break
			else
				
				writingMap=true
			fi
		fi

		if [[ $writingMap == true ]]; then

			if [[ $line == *"0x"* ]]; then
				echo $line >> $MAP_OUTPUT_FILE
			fi
		fi
			
	done < $file
done

for file in $FILES; do
	rm $file
done

rm -f $OUTPUT_FILE
let numberOfTiles=biggerTilesArray/4
echo "// Number of frames: ${numberOfFrames}" > $OUTPUT_FILE
echo "// Number of chars per frame: ${numberOfTiles}" >> $OUTPUT_FILE
echo " " >> $OUTPUT_FILE
echo "const unsigned int ${NAME}Tiles[] __attribute__((aligned(4))) = " >> $OUTPUT_FILE
echo "{" >> $OUTPUT_FILE
cat $TILES_OUTPUT_FILE >> $OUTPUT_FILE
echo "};" >> $OUTPUT_FILE
echo " " >> $OUTPUT_FILE
echo "const unsigned short ${NAME}Map[] __attribute__((aligned(4)))=" >> $OUTPUT_FILE
echo "{" >> $OUTPUT_FILE
cat $MAP_OUTPUT_FILE >> $OUTPUT_FILE
echo "};" >> $OUTPUT_FILE
echo "" >> $OUTPUT_FILE

rm -f $TILES_OUTPUT_FILE
rm -f $MAP_OUTPUT_FILE

mv $OUTPUT_FILE $FINAL_OUTPUT_FILE

