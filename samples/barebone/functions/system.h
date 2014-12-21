void initSystem()
{
	//timer interrupts setup
	setupTimer();
	
	//column table setup
	//vbSetColTable();
	
	//display setup
	vbDisplayOn();
	
	//load font
	copymem((void*)(CharSeg3+0x1000), (void*)FontTiles, 256*16);
}