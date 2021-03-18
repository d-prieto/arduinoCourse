# Epilog Laser Tutorial (from Castelldefels Tinkerers lab)

This documentation is about how to use the Epilog laser. 

This is intended for people who are already familiar with other laser cutting machines. But I'll try to keep it accessible. 

## Epilog laser 

This beauty is small but very good. It has limited cutting power but it's cozy and functional. Beware that it won't cut in one run a 5mm acrylic. 

Right now is installed in one of the computers but it's connected through network so it could be installed ino all of them or other computers if you share the network. 

## Safety first

![](https://netrunnerdb.com/card_image//large/09044.jpg)

_Bioroids now that safety comes first_

Ok, so safety first. To operate the laser (or any laser) you should know that

* Things can catch fire and/or produce fumes.

So you should check out where is the fire extinguisher (right now is next to the laser). 

Also you should be always near the lasercut when it's cutting. If you have to go to the bathroom, you have to stop the machine, go to attend the body's duty, and then resume the job. 

Also you have to start the auxiliary systems _before_ starting cutting. That is the compressor (right now it's on the CNC side) and the extractor (it's on the right of the lasercut, like a meter away). 

## Starting the machine. 

This routine it's around 30 seconds so you can configure the files before having a lot of noise. 

First, you have also to switch on the compressor and the filter. 


This machine is disconnected fully from the current when it's out so it deletes the previous jobs. So you have to plug and unplug it to turn it on or off. It will start the routine of start and it' will be ready to go. 


## Configuring the files. 

This machine only engraves or cuts. It can't do 2 things in the same job.Take that into acount. 

In this document I differenciate engraving and cutting between how the laser operates rather than the consecuences of the movement:

* Raster/engraving is the movement that the laser does scanlines and in some points it makes goes on and some points it goes off
* Vector/cutting is the movment that the laser goes following the lines of the drawing. 

Both could (depending on the parameters and material cut through or just carve the stock). 

How they work. 

If you set to raster. The file is going to be just engraved with the power and the speed you have set up. That means that it's going to rasterize everything you could make and send it to the laser. The good thing that this works with raster files (yay). The bad thing is that if you're looking for a cut or a vector engraving this won't do. 

If you set the vector it's going to try to look for the vectors and cut through with the parameters. I don't use usually this setting. I prefer to go to advanced and set the colour mapping to fix the power and the speed for each file. 

### Known materials 

3 mm acrylic. 7 Speed, 100 power, Max. Frecuency. 
5 mm acrylic. 9 Speed, 100 power, Max. Frecuency. 2 passes

### Inkscape 

Inkscape has _problems_ dealing with the epilog. It's better to print PDF and then send the pdfs to cut. When you set the settings for the epilog, they reset themselves to the default. So apart of doing default engraving is hard to work with it. 

### PDF 

You can work with PDF made with inkscape, Rhinoceros, Illustrator or the program of your choice. 

To cut the lines have to be less than 0.2 thick to cut through

### Rhino case 

I have a file of A3 that has something engraved and something cut through. I don't have in this case lines that doesn't go through. So I need 2 jobs. One for the raster and 1 for the cut through 

I need to know the size of the stock A3 and I draw a rectangle of that size. 

_Pro tip:_

When you print the rectangle somehow... goes through. To skip it and let the 





