#include<stdio.h>
#include<math.h>
#define PI 3.1415926535897
#define HEIGHT_WIDTH 1000
typedef struct BMPSIN BMPSIN;
int main(int argc, char **argv)
{
int w=1000, h=1000;
FILE *f=fopen(argv[1],"wb");
unsigned char rgb[HEIGHT_WIDTH][HEIGHT_WIDTH][3];
unsigned char bmpfileheader[14] = {'B','M', 0,0,0,0, 0,0, 0,0, 54,0,0,0};
unsigned char bmpinfoheader[40] = {40,0,0,0, 0,0,0,0, 0,0,0,0, 1,0, 24,0};
int filesize=54+3*HEIGHT_WIDTH*HEIGHT_WIDTH;
bmpfileheader[ 2] = (unsigned char)(filesize    );
bmpfileheader[ 3] = (unsigned char)(filesize>> 8);
bmpfileheader[ 4] = (unsigned char)(filesize>>16);
bmpfileheader[ 5] = (unsigned char)(filesize>>24);

bmpinfoheader[ 4] = (unsigned char)(       w    );
bmpinfoheader[ 5] = (unsigned char)(       w>> 8);
bmpinfoheader[ 6] = (unsigned char)(       w>>16);
bmpinfoheader[ 7] = (unsigned char)(       w>>24);
bmpinfoheader[ 8] = (unsigned char)(       h    );
bmpinfoheader[ 9] = (unsigned char)(       h>> 8);
bmpinfoheader[10] = (unsigned char)(       h>>16);
bmpinfoheader[11] = (unsigned char)(       h>>24);

f = fopen(argv[1],"wb");
fwrite(bmpfileheader,1,14,f);
fwrite(bmpinfoheader,1,40,f);
int i,co,x;
for(i=0;i<HEIGHT_WIDTH;i+=1)
    {
        co=300+50*cos(3*(PI*i/180.0));
        for(x=0;x<co;x++)
            {
                rgb[x][i][0]=(unsigned char)255;
                rgb[x][i][1]=(unsigned char)255;
                rgb[x][i][2]=(unsigned char)255;
            }
        x++;
        rgb[x][i][0]=(unsigned char)0;
        rgb[x][i][1]=(unsigned char)0;
        rgb[x][i][2]=(unsigned char)0;
        x++;
        while(x<1000)
        {
            rgb[x][i][0]=255;
            rgb[x][i][1]=255;
            rgb[x][i][2]=255;

            x++;
        }
    }
fwrite(rgb,sizeof(rgb),1,f);
fclose(f);
return 0;
}

