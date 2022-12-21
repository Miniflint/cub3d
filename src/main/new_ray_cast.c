#include "../../inc/cub3d.h"

int FixAng(int a)
{
    if(a>359)
        a-=360;
    if(a<0)
        a+=360;
    return a;
}

double degToRad(double deg)
{
	return (deg / 57.29578);
}

/*
void drawRays2D(t_all *all, t_data *img)
{
    int r,mx,my,mp,dof,side;
	double vx,vy,rx,ry,ra,xo,yo,disV,disH;
    double Tan;
 
    ra = FixAng(all->player.angle); //ray set back 30 degrees
    for (r=0;r<1;r++)
    { //---Vertical--- 
        dof=0;
        side=0;
        disV=100000;
        Tan = tan(degToRad(ra));
        if(cos(degToRad(ra))> 0.001)
        {
            rx=((int)all->player.x)+1;
            ry=(all->player.x - rx) * Tan + all->player.y;
            xo= 1;
            yo= -xo * Tan;
        }//looking left
        else if (cos(degToRad(ra))<-0.001)
        {
            rx=((int)all->player.x)-0.0001;
            ry=(all->player.x - rx) * Tan + all->player.y;
            xo=-1;
            yo=-xo*Tan;
        }//looking right
        else
        {
            rx=all->player.x;
            ry=all->player.y;
            dof=8;
        }//looking up or down. no hit  

        while(dof<8) 
        { 
            mx = (int)(rx);
            my = (int)(ry);
            mp = my * mapX + mx;
            if (mp > 0 && mp < mapX * mapY && map[mp] == '1')
            {
                dof = 8;
                disV = cos(degToRad(ra)) * (rx-px) - sin(degToRad(ra)) * (ry - py);
            }//hit         
            else
            {
                rx+=xo;
                ry+=yo;
                dof+=1;
            }//check next horizontal
        } 
        vx=rx; vy=ry;

        //---Horizontal---
        dof=0;
        disH=100000;
        Tan= 1.0 / Tan;
    
        if(sin(degToRad(ra))> 0.001)
        {
            ry=(((int)py>>6)<<6) -0.0001;
            rx=(py - ry) * Tan + px;
            yo = -64;
            xo = -yo * Tan;
        }//looking up 
        else if(sin(degToRad(ra)) < -0.001)
        {
            ry = (((int)py>>6)<<6)+64;
            rx = (py-ry) * Tan + px;
            yo = 64;
            xo = -yo * Tan;
        }//looking down
        else
        {
            rx = px;
            ry=py;
            dof=8;
        }//looking straight left or right

        while(dof<8) 
        { 
            mx = (int)(rx)>>6;
            my = (int)(ry)>>6;
            mp = my * mapX + mx;
            if(mp > 0 && mp < mapX * mapY && map[mp]=='1')
            {
                dof=8;
                disH = cos(degToRad(ra)) * (rx - px) - sin(degToRad(ra)) * (ry-py);
            }//hit
            else
            {
                rx += xo;
                ry += yo;
                dof += 1;
            }//check next horizontal
        }
        if(disV < disH)
        {
            rx = vx;
            ry=vy;
            disH=disV;
        }//horizontal hit first

        int ca=FixAng(pa-ra);
        disH = disH * cos(degToRad(ca)); //fix fisheye 
        int lineH = (mapS * 320) / (disH);
        if(lineH>320)
            lineH=320;//line height and limit
        int lineOff = 160 - (lineH>>1);//line offset
        ra = FixAng(ra-1);//go to next ray
    }
}
*/