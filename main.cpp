#include <iostream>
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL2_gfx.h>
#include <string>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <SDL2/SDL_mixer.h>
#include <SDL_mixer.h>


using namespace std;
void window_color(SDL_Renderer *Renderer, int R, int G, int B);
void rect(SDL_Renderer *Renderer, int x,int y,int w,int h,int R, int G, int B, int fill_boolian );
void ellipse(SDL_Renderer *Renderer, int x, int y, int Radius1, int Radius2, int R, int G, int B, int fill_boolian);
void texture(SDL_Renderer *m_renderer,int xp,int yp,string addressOfImage,int width,int height);
void text1(SDL_Renderer *m_renderer,int x_position,int y_position,const char * text,int font,int R,int G,int B,int A,int sizefont );
void HomePage(SDL_Renderer *m_renderer,int W,int H);
void SettingPage(SDL_Renderer *m_renderer,int H,int W);
void NamePage(SDL_Renderer *m_renderer,int W,int H);
void ScoreboardPage(SDL_Renderer *m_renderer,int W,int H);
void getkey1(SDL_Renderer *m_renderer,struct pic inputbox1);
void getkey2(SDL_Renderer *m_renderer,struct pic inputbox2);
void ChoosePage(SDL_Renderer *m_renderer,int W,int H);
void AboutPage(SDL_Renderer *m_renderer,int W,int H);

string player1name="";
string player2name="";
bool ReloadHomepage=false,K1toK2=false;
bool waswritten1=true,waswritten2=true,choosepage=false;
    bool player1char=1;  // 1=ronaldo 0=messi
    bool player2char=0;
bool kfa=0,kfb=0,hfa=0,hfb=0,tca=0,tcb=0,iba=0,ibb=0,swa=0,swb=0,pua=0,pub=0;
bool startgame=false,oktime=0,okgoal=0;
int goalwin=1,timegame=60;
int volumefirst=10,volumeplay=10;
bool backhome=0;
struct pic
{
    double xp;
    double yp;
    double w;
    double h;
};
struct mouse
{
    int x;
    int y;
};


int main( int argc , char * argv[] )
{
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
    Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,2,2048);
          Mix_VolumeMusic(volumefirst);

    Mix_Music *backgroundSound = Mix_LoadMUS("90.MP3");

    //Initialization of SDL windows
    Uint32 SDL_flags = SDL_INIT_VIDEO | SDL_INIT_TIMER ;
    Uint32 WND_flags = SDL_WINDOW_SHOWN | SDL_WINDOW_FULLSCREEN_DESKTOP;//SDL_WINDOW_BORDERLESS ;
    SDL_Window * m_window;
    SDL_Renderer * m_renderer;
    Mix_PlayMusic(backgroundSound,-1);
//    Mix_FreeMusic(backgroundSound);


    SDL_Init( SDL_flags );
    SDL_CreateWindowAndRenderer( 1200, 800, WND_flags, &m_window, &m_renderer );
    SDL_RaiseWindow(m_window);
    SDL_DisplayMode DM;
    SDL_GetCurrentDisplayMode(0, &DM);
    int W = DM.w;
    int H = DM.h;
    SDL_SetRenderDrawColor( m_renderer, 0, 0, 0, 255 );
    SDL_RenderClear( m_renderer );

HomePage(m_renderer,W,H);
while(ReloadHomepage && startgame==0) HomePage(m_renderer,W,H);
if(ReloadHomepage==0 && startgame==0) return 0;

     if(oktime==0 && okgoal==0)
     {
         oktime=1;
     }
    texture(m_renderer,0,0,"pish.gif",W,H);


    SDL_RenderPresent( m_renderer );
    SDL_Delay(1000);
    SDL_RenderClear( m_renderer );




    SDL_Event *e = new SDL_Event();

    int g1=0,g2=0,w1=0,w2=0,l1=0,l2=0,d1=0,d2=0;
    double xb=W/2,yb=H/2,dyb=10;
    int r=25 , R=255, B=255, G=255;
    double dxb=0,theta1=0,theta2=0;
    int timeplay;
    int floor=650,wr=50;
    int hashie=200;
    int wall_right=hashie,wall_left=W-hashie,time_pause1=0,time_pause2=0;
    int tball=0,t=W,d_xb,f=37,l=20,ax=10,ay=5,h_net=300,w_net=wall_right,xgoal=120,xgoal2=xgoal,xgoal1=W-xgoal,ygoal=400;
    double ayb=1;
    bool flag1=0,flag2=0,shoot_zamini1=0,shoot_zamini2=0,shoot_havaee1=0,shoot_havaee2=0,tripple_clone1=0,tripple_clone2=0;
    bool stop_ball=1,fall1=0,fall2=0,kick_fire1=0,kick_fire2=0,b1=0,b2=0;
    int wp=150,wp1=150,wp2=150,hp=150,counter1=-1,counter2=-1;
    int xp1=xgoal1-wp1,yp1=floor-hp,dyp1=-10,dyp2=-10,Rp1=100,Bp1=100,Gp1=100;
    int xp2=xgoal2,yp2=yp1,fargh=35,fargh1=fargh,fargh2=fargh;
    int x_sargardan,y_sargardan,w_sargardan=50,h_sargardan=50,rRotX=80,rRotY=60;
    int font =2;
    int x_time=W/2-120;
    int y_time=5;
    int head=100,nose=65,counter3=200,counter4=200,xp12,xp13,xp22,xp23,ragham;
    char round_ball='1';
    bool ball=1,punch1=0,punch2=0,head_fire1=0,head_fire2=0,tir1=0,tir2=0,wall1=0,wall2=0,pause=1,v_tir=0,shoot=0,boolprize1=1,boolprize2=1;
    int helpme1=W,helpme2=0,finish,xwall2=50,xwall1=W-w_net-50,counter_wall1=0,counter_wall2=0,wall_barkhord1=xwall1+80,wall_barkhord2=xwall2+w_net-80;
    //char player1='M',player2='R';
    string p11,p22,p23,h1,h2,p21,f1,f2,p12,p13,stime;
    bool aa1=1,bb1=1,cc1=1,bb2=1,cc2=1,aa2=1,v_punch=0,collision=0,vfall=0;
    int volume=10,prize1,prize2,c=0,tp1=1,tp2=1;


    if(player2char==0){
        p11="M 1 1.png";
        f1="M 1 f.png";
        h1="M 1 h.png";
        p12="M 1 2.png";
        p13="M 1 3.png";
    }
    else{
        p11="R 1 1.png";
        f1="R 1 f.png";
        p12="R 1 2.png";
        p13="R 1 3.png";
        h1="M 1 h.png";
    }
    if(player1char==0){
        p21="M 2 1.png";
        f2="M 2 f.png";
        p22="M 2 2.png";
        p23="M 2 3.png";
        h2="M 2 h.png";
    }
    else{
        f2="R 2 f.png";
        p21="R 2 1.png";
        p22="R 2 2.png";
        p23="R 2 3.png";
        h2="R 2 h.png";
    }
    srand(time(NULL));
    int start=clock(),timeplus=0,ta2,ta1,tb1,tb2,tb3,ta3,xz1,yz1,xz2,yz2;
    const char * showtime;
    bool pz1=0,pz2=0,power_start1=0,power_start2=0,goalshod=0;
    int counterz1=0,counterz2=0,power1=0,power2=0,hpower=50,wpower=100,xpower=(W*8)/9,ypower=30;
    if(timegame>=60)
    {
    ta3=rand()%20+10;
    tb3=rand()%20+10;

    }
    if(timegame>=90 )
    {
    ta2=rand()%30+40;
    tb2=rand()%30+40;
    if(timegame>=120)
    {
        ta1=rand()%25+85;
        tb1=rand()%25+85;
    }
    }
        Mix_FreeMusic(backgroundSound);
        texture(m_renderer,0,0,"st.jpg",W,H);
//        texture(m_renderer,W/2+20,H/4,"a fans.jpg",W/2-20,H/4+80);
//        texture(m_renderer,0,H/4,"b fans.jpg",W/2-20,H/4+80);

        texture(m_renderer,W-w_net,floor-h_net+20,"net1.png",w_net,h_net);
        texture(m_renderer,0,floor-h_net+20,"net2.png",w_net,h_net);
        texture(m_renderer,xb-r,yb-r,"ball1.png",2*r,2*r);
        texture(m_renderer,xp1,yp1,p11,wp,hp);
        texture(m_renderer,xp2,yp2,p21,wp,hp);
        SDL_RenderPresent(m_renderer);
        SDL_Delay(1000);
        Mix_Chunk *whistle = Mix_LoadWAV("whistle.wav");
        Mix_PlayChannel(-1,whistle,0);
        Mix_Music *vplay = Mix_LoadMUS("footbalist.MP3");

        Mix_PlayMusic(vplay,-1);


    Mix_Chunk *vshoot = Mix_LoadWAV("shoot.wav");
    Mix_Chunk *colllision_sound = Mix_LoadWAV("collision.wav");
    Mix_Chunk *tir = Mix_LoadWAV("tir.wav");
    Mix_Chunk *sound_punch = Mix_LoadWAV("vpunch.wav");
    Mix_Chunk *vgoal = Mix_LoadWAV("goal.wav");
    Mix_Chunk *vwin = Mix_LoadWAV("win sound.wav");


    while(1)
    {
        volumeplay=volume/2;
      Mix_VolumeMusic(volumeplay);
      Mix_VolumeChunk(whistle,volume);
      Mix_VolumeChunk(vshoot,volume);
      Mix_VolumeChunk(tir,volume);
      Mix_VolumeChunk(sound_punch,volume);
      Mix_VolumeChunk(vgoal,volume);
      Mix_VolumeChunk(vwin,volume);






      if(pause)
      {

        SDL_PollEvent(e);
        texture(m_renderer,0,0,"st.jpg",W,H);
//        texture(m_renderer,W/2+20,H/4,"a fans.jpg",W/2-20,H/4+80);
//        texture(m_renderer,0,H/4,"b fans.jpg",W/2-20,H/4+80);

        texture(m_renderer,W-w_net,floor-h_net+20,"net1.png",w_net,h_net);
        texture(m_renderer,0,floor-h_net+20,"net2.png",w_net,h_net);
        texture(m_renderer,10,10,"pause.png",50,50);

        texture(m_renderer,xpower-70,ypower,"A.png",50,50);
        texture(m_renderer,xpower-70,ypower+hpower+20,"B.png",50,50);
        //vlineRGBA(m_renderer,xgoal1,0,H,255,255,255,255);
        //vlineRGBA(m_renderer,xgoal2,0,H,255,255,255,255);
        //aaaaaaaaaaaaaaavlineRGBA(m_renderer,xgoal1+70,0,H,255,255,255,255);

        //hlineRGBA(m_renderer,0,W,ygoal,255,255,255,255);

        if(power_start2){
        rect(m_renderer,xpower,ypower+hpower+20,power2/10,hpower,0,255,0,1);
        rect(m_renderer,xpower+power2/10,ypower+hpower+20,wpower-power2/10,hpower,255,255,255,1);

        texture(m_renderer,xpower-2,ypower+hpower+15,"bat.png",wpower+12,hpower+10);

        power2++;
        if(power2==1000)
        {
            power_start2=0;
            power2=0;
        }
        }
        else
        {

            rect(m_renderer,xpower,ypower+hpower+20,wpower,hpower,0,255,0,1);
        texture(m_renderer,xpower-2,ypower+hpower+15,"bat.png",wpower+12,hpower+10);
        }
        if(power_start1){
        rect(m_renderer,xpower,ypower,power1/10,hpower,0,255,0,1);
        rect(m_renderer,xpower+power1/10,ypower,wpower-power1/10,hpower,255,255,255,1);
        texture(m_renderer,xpower-2,ypower-5,"bat.png",wpower+12,hpower+10);
        power1++;
        if(power1==1000)
        {
            power_start1=0;
            power1=0;
        }
        }
        else
        {

            rect(m_renderer,xpower,ypower,wpower,hpower,0,255,0,1);
        texture(m_renderer,xpower-2,ypower-5,"bat.png",wpower+12,hpower+10);
        }
            if(oktime){

        start+=time_pause2-time_pause1;
        time_pause1=0;
        time_pause2=0;

        timeplay=timegame-int((clock()-start)/1000.0)+timeplus+1;
        ragham=timeplay/100;
        if(timeplay>10)
        {
        if(ragham==0)
        { ragham=timeplay/10;
            switch(ragham)
            {
            case 1:
                texture(m_renderer,W/2-wr,10,"1 g.png",wr,wr);
             break;
            case 2:
                texture(m_renderer,W/2-wr,10,"2 g.png",wr,wr);
             break;
            case 3:
                texture(m_renderer,W/2-wr,10,"3 g.png",wr,wr);
             break;
            case 4:
                texture(m_renderer,W/2-wr,10,"4 g.png",wr,wr);
             break;
            case 5:
                texture(m_renderer,W/2-wr,10,"5 g.png",wr,wr);
             break;
            case 6:
                texture(m_renderer,W/2-wr,10,"6 g.png",wr,wr);
             break;
            case 7:
                texture(m_renderer,W/2-wr,10,"7 g.png",wr,wr);
             break;
            case 8:
                texture(m_renderer,W/2-wr,10,"8 g.png",wr,wr);
             break;
            case 9:
                texture(m_renderer,W/2-wr,10,"9 g.png",wr,wr);
             break;
            }
            ragham=timeplay%10;
            switch(ragham)
            {
            case 0:
                texture(m_renderer,W/2,10,"0 g.png",wr,wr);
             break;
            case 1:
                texture(m_renderer,W/2,10,"1 g.png",wr,wr);
             break;
            case 2:
                texture(m_renderer,W/2,10,"2 g.png",wr,wr);
             break;
            case 3:
                texture(m_renderer,W/2,10,"3 g.png",wr,wr);
             break;
            case 4:
                texture(m_renderer,W/2,10,"4 g.png",wr,wr);
             break;
            case 5:
                texture(m_renderer,W/2,10,"5 g.png",wr,wr);
             break;
            case 6:
                texture(m_renderer,W/2,10,"6 g.png",wr,wr);
             break;
            case 7:
                texture(m_renderer,W/2,10,"7 g.png",wr,wr);
             break;
            case 8:
                texture(m_renderer,W/2,10,"8 g.png",wr,wr);
             break;
            case 9:
                texture(m_renderer,W/2,10,"9 g.png",wr,wr);
             break;
            }

        }
        else
        {
            switch(ragham)
            {
            case 1:
                texture(m_renderer,W/2-3*wr/2,10,"1 g.png",wr,wr);
             break;
            case 2:
                texture(m_renderer,W/2-3*wr/2,10,"2 g.png",wr,wr);
             break;
            case 3:
                texture(m_renderer,W/2-3*wr/2,10,"3 g.png",wr,wr);
             break;
            case 4:
                texture(m_renderer,W/2-3*wr/2,10,"4 g.png",wr,wr);
             break;
            case 5:
                texture(m_renderer,W/2-3*wr/2,10,"5 g.png",wr,wr);
             break;
            case 6:
                texture(m_renderer,W/2-3*wr/2,10,"6 g.png",wr,wr);
             break;
            case 7:
                texture(m_renderer,W/2-3*wr/2,10,"7 g.png",wr,wr);
             break;
            case 8:
                texture(m_renderer,W/2-3*wr/2,10,"8 g.png",wr,wr);
             break;
            case 9:
                texture(m_renderer,W/2-3*wr/2,10,"9 g.png",wr,wr);
             break;
            }
            ragham=(timeplay/10)%10;
            switch(ragham)
            {
            case 0:
                texture(m_renderer,W/2-wr/2,10,"0 g.png",wr,wr);
             break;
            case 1:
                texture(m_renderer,W/2-wr/2,10,"1 g.png",wr,wr);
             break;
            case 2:
                texture(m_renderer,W/2-wr/2,10,"2 g.png",wr,wr);
             break;
            case 3:
                texture(m_renderer,W/2-wr/2,10,"3 g.png",wr,wr);
             break;
            case 4:
                texture(m_renderer,W/2-wr/2,10,"4 g.png",wr,wr);
             break;
            case 5:
                texture(m_renderer,W/2-wr/2,10,"5 g.png",wr,wr);
             break;
            case 6:
                texture(m_renderer,W/2-wr/2,10,"6 g.png",wr,wr);
             break;
            case 7:
                texture(m_renderer,W/2-wr/2,10,"7 g.png",wr,wr);
             break;
            case 8:
                texture(m_renderer,W/2-wr/2,10,"8 g.png",wr,wr);
             break;
            case 9:
                texture(m_renderer,W/2-wr/2,10,"9 g.png",wr,wr);
             break;
            }
            ragham=timeplay%10;
            switch(ragham)
            {
            case 0:
                texture(m_renderer,W/2+wr/2,10,"0 g.png",wr,wr);
             break;
            case 1:
                texture(m_renderer,W/2+wr/2,10,"1 g.png",wr,wr);
             break;
            case 2:
                texture(m_renderer,W/2+wr/2,10,"2 g.png",wr,wr);
             break;
            case 3:
                texture(m_renderer,W/2+wr/2,10,"3 g.png",wr,wr);
             break;
            case 4:
                texture(m_renderer,W/2+wr/2,10,"4 g.png",wr,wr);
             break;
            case 5:
                texture(m_renderer,W/2+wr/2,10,"5 g.png",wr,wr);
             break;
            case 6:
                texture(m_renderer,W/2+wr/2,10,"6 g.png",wr,wr);
             break;
            case 7:
                texture(m_renderer,W/2+wr/2,10,"7 g.png",wr,wr);
             break;
            case 8:
                texture(m_renderer,W/2+wr/2,10,"8 g.png",wr,wr);
             break;
            case 9:
                texture(m_renderer,W/2+wr/2,10,"9 g.png",wr,wr);
             break;
            }

            }

        }
        else
        {

        if(ragham==0)
        {
             ragham=timeplay/10;
                switch(ragham)
            {

            case 1:
                texture(m_renderer,W/2-wr,10,"1 r.png",wr,wr);
             break;
            case 2:
                texture(m_renderer,W/2-wr,10,"2 r.png",wr,wr);
             break;
            case 3:
                texture(m_renderer,W/2-wr,10,"3 r.png",wr,wr);
             break;
            case 4:
                texture(m_renderer,W/2-wr,10,"4 r.png",wr,wr);
             break;
            case 5:
                texture(m_renderer,W/2-wr,10,"5 r.png",wr,wr);
             break;
            case 6:
                texture(m_renderer,W/2-wr,10,"6 r.png",wr,wr);
             break;
            case 7:
                texture(m_renderer,W/2-wr,10,"7 r.png",wr,wr);
             break;
            case 8:
                texture(m_renderer,W/2-wr,10,"8 r.png",wr,wr);
             break;
            case 9:
                texture(m_renderer,W/2-wr,10,"9 r.png",wr,wr);
             break;
            }
            ragham=timeplay%10;
            switch(ragham)
            {
            case 0:
                texture(m_renderer,W/2,10,"0 r.png",wr,wr);
             break;
            case 1:
                texture(m_renderer,W/2,10,"1 r.png",wr,wr);
             break;
            case 2:
                texture(m_renderer,W/2,10,"2 r.png",wr,wr);
             break;
            case 3:
                texture(m_renderer,W/2,10,"3 r.png",wr,wr);
             break;
            case 4:
                texture(m_renderer,W/2,10,"4 r.png",wr,wr);
             break;
            case 5:
                texture(m_renderer,W/2,10,"5 r.png",wr,wr);
             break;
            case 6:
                texture(m_renderer,W/2,10,"6 r.png",wr,wr);
             break;
            case 7:
                texture(m_renderer,W/2,10,"7 r.png",wr,wr);
             break;
            case 8:
                texture(m_renderer,W/2,10,"8 r.png",wr,wr);
             break;
            case 9:
                texture(m_renderer,W/2,10,"9 r.png",wr,wr);
             break;
            }

        }
        else
        {
            switch(ragham)
            {
            case 1:
                texture(m_renderer,W/2-3*wr/2,10,"1 r.png",wr,wr);
             break;
            case 2:
                texture(m_renderer,W/2-3*wr/2,10,"2 r.png",wr,wr);
             break;
            case 3:
                texture(m_renderer,W/2-3*wr/2,10,"3 r.png",wr,wr);
             break;
            case 4:
                texture(m_renderer,W/2-3*wr/2,10,"4 r.png",wr,wr);
             break;
            case 5:
                texture(m_renderer,W/2-3*wr/2,10,"5 r.png",wr,wr);
             break;
            case 6:
                texture(m_renderer,W/2-3*wr/2,10,"6 r.png",wr,wr);
             break;
            case 7:
                texture(m_renderer,W/2-3*wr/2,10,"7 r.png",wr,wr);
             break;
            case 8:
                texture(m_renderer,W/2-3*wr/2,10,"8 r.png",wr,wr);
             break;
            case 9:
                texture(m_renderer,W/2-3*wr/2,10,"9 r.png",wr,wr);
             break;
            }
            ragham=(timeplay/10)%10;
            switch(ragham)
            {
            case 0:
                texture(m_renderer,W/2-wr/2,10,"0 r.png",wr,wr);
             break;
            case 1:
                texture(m_renderer,W/2-wr/2,10,"1 r.png",wr,wr);
             break;
            case 2:
                texture(m_renderer,W/2-wr/2,10,"2 r.png",wr,wr);
             break;
            case 3:
                texture(m_renderer,W/2-wr/2,10,"3 r.png",wr,wr);
             break;
            case 4:
                texture(m_renderer,W/2-wr/2,10,"4 r.png",wr,wr);
             break;
            case 5:
                texture(m_renderer,W/2-wr/2,10,"5 r.png",wr,wr);
             break;
            case 6:
                texture(m_renderer,W/2-wr/2,10,"6 r.png",wr,wr);
             break;
            case 7:
                texture(m_renderer,W/2-wr/2,10,"7 r.png",wr,wr);
             break;
            case 8:
                texture(m_renderer,W/2-wr/2,10,"8 r.png",wr,wr);
             break;
            case 9:
                texture(m_renderer,W/2-wr/2,10,"9 r.png",wr,wr);
             break;
            }
            ragham=timeplay%10;
            switch(ragham)
            {
            case 0:
                texture(m_renderer,W/2+wr/2,10,"0 r.png",wr,wr);
             break;
            case 1:
                texture(m_renderer,W/2+wr/2,10,"1 r.png",wr,wr);
             break;
            case 2:
                texture(m_renderer,W/2+wr/2,10,"2 r.png",wr,wr);
             break;
            case 3:
                texture(m_renderer,W/2+wr/2,10,"3 r.png",wr,wr);
             break;
            case 4:
                texture(m_renderer,W/2+wr/2,10,"4 r.png",wr,wr);
             break;
            case 5:
                texture(m_renderer,W/2+wr/2,10,"5 r.png",wr,wr);
             break;
            case 6:
                texture(m_renderer,W/2+wr/2,10,"6 r.png",wr,wr);
             break;
            case 7:
                texture(m_renderer,W/2+wr/2,10,"7 r.png",wr,wr);
             break;
            case 8:
                texture(m_renderer,W/2+wr/2,10,"8 r.png",wr,wr);
             break;
            case 9:
                texture(m_renderer,W/2+wr/2,10,"9 r.png",wr,wr);
             break;
            }

            }
        }

        if(timeplay==ta1 || timeplay==ta2 || timeplay==ta3)
        {
            if(timeplay==ta2)
                cc1=1;
            if(timeplay==ta3)
                bb1=1;
      if(!pz1&& aa1 && bb1 && cc1)
        {
             xz1=rand()%(W-600)+300;
             yz1=rand()%H/2-H/2+floor;
            pz1=1;
            counterz1=200;
            if(timeplay==ta1)
                cc1=0;
            if(timeplay==ta2)
                bb1=0;
            if(timeplay==ta3)
                aa1=0;
        }
        }
        if(pz1)
        {
            texture(m_renderer,xz1,yz1,"z r.png",100,100);
            counterz1--;
            if(counterz1==0 )
            {
                pz1=0;
            }

        }

        if(timeplay==tb1 || timeplay==tb2 || timeplay==tb3 )
        {
            if(timeplay==tb2)
                cc2=1;
             if(timeplay==tb3)
                bb2=1;
            if(!pz2 && cc2&& bb2 && aa2)
            {


             xz2=rand()%(W-600)+300;
             yz2=rand()%H/2-H/2+floor;
            pz2=1;
            counterz2=200;
            if(timeplay==tb1)
                cc2=0;
            if(timeplay==tb2)
                bb2=0;
            if(timeplay==tb3)
                aa2=0;
            }
        }

        if(pz2)
        {
            texture(m_renderer,xz2,yz2,"z b.png",100,100);
            counterz2--;

            if(counterz2==0)
            {
                pz2=0;
            }


        }
        }
        if(!oktime)
        {
            c++;

            if(boolprize1)
            {
                prize1=rand()%600+600*(tp1);
                 boolprize1=0;
                             tp1++;

            }
            if(c==prize1)
            {
                boolprize1=1;
            xz1=rand()%(W-600)+300;
             yz1=rand()%H/2-H/2+floor;
            pz1=1;
            counterz1=200;
            }
            if(boolprize2)
            {
                prize2=rand()%600+600*(tp2);
                boolprize2=0;
                            tp2++;

            }
            if(c==prize2)
            {
                boolprize2=1;
            xz2=rand()%(W-600)+300;
             yz2=rand()%H/2-H/2+floor;
            pz2=1;
            counterz2=200;
            }


        if(pz1)
        {
            texture(m_renderer,xz1,yz1,"z r.png",100,100);
            counterz1--;
            if(counterz1==0 )
            {
                pz1=0;
            }

        }
        if(pz2)
        {
            texture(m_renderer,xz2,yz2,"z b.png",100,100);
            counterz2--;

            if(counterz2==0)
            {
                pz2=0;
            }


        }
        }



        if(okgoal || oktime)
        {
        if(timeplay<=0 || (okgoal&& (g1>=goalwin || g2>=goalwin)))
            {
         const char * text ="";
              SDL_RenderClear(m_renderer);

            if(g1>g2)
               {
                    Mix_FreeMusic(vplay);

                   Mix_PlayChannel(-1,vwin,0);

                   w1++;
                   l2++;
                   text=player1name.c_str();
                       texture(m_renderer,0,0,"fin win 1.jpg",W,H);
                        text1(m_renderer,W/2-500,2*H/5-330,text,2,0,0,0,255,300);
                   text="wins!";
                        text1(m_renderer,W/2-450,2*H/5-30,text,2,0,0,0,255,300);

               }
               else if(g2>g1)
               {
                   Mix_FreeMusic(vplay);

                   Mix_PlayChannel(-1,vwin,0);

                   w2++;
                   l1++;
                    text=player2name.c_str();
                  texture(m_renderer,0,0,"fin win 2.png",W,H);
                        text1(m_renderer,W/2-500,2*H/5-330,text,2,0,0,0,255,300);
                   text="wins!";
                        text1(m_renderer,W/2-450,2*H/5-30,text,2,0,0,0,255,300);
               }
               else
               {
                   Mix_FreeMusic(vplay);
                   Mix_Music *draw = Mix_LoadMUS("draw.MP3");

                   Mix_PlayMusic(draw,-1);
                   d1++;
                   d2++;
                texture(m_renderer,0,0,"fin win 3.png",W,H);
                text="Draw!";
                        text1(m_renderer,W/2-500,2*H/5-200,text,2,0,0,255,255,300);
               }
              SDL_RenderPresent(m_renderer);
              SDL_Delay(5000);
               string playernamedata[20]="";
            short int games[20],wins[20],draw[20],lose[20],gf[20],ga[20],gp[20],pts[20];
            int i=0;
            ifstream in;
            ofstream out;
            in.open("data.txt");
            if( in.good() )
            {

                //bool dot=0;
                while( 1 )
                {
                    //if(playernamedata[i]=="end") break;//dot=1;
                    //else{
                    in>>playernamedata[i];
                    if(playernamedata[i]!="end") in>>games[i]>>wins[i]>>draw[i]>>lose[i]>>gf[i]>>ga[i]>>gp[i]>>pts[i];
                    else break;
                    //cout<<playernamedata[i];
                    i++;

                    //}
                }

             in.close();
            }

            bool exist1=0,exist2=0;
            for(int k=0;k<i;k++)
            {
                if(playernamedata[k]==player1name)
                {
                    exist1=1;
                    games[k]++;
                    if(g1>g2)
                    {
                    wins[k]++;
                    pts[k]+=3;
                    }
                    else if(g1<g2) lose[k]++;
                    else if(g1==g2)
                    {
                        draw[k]++;
                        pts[k]++;
                    }
                    gf[k]=gf[k]+g1;
                    ga[k]=ga[k]+g2;
                    gp[k]=gp[k]+g1-g2;

                }

                else if(playernamedata[k]==player2name)
                {
                    exist2=1;
                    games[k]++;
                    if(g2>g1)
                    {
                    wins[k]++;
                    pts[k]+=3;
                    }
                    else if(g2<g1) lose[k]++;
                    else if(g1==g2)
                    {
                        draw[k]++;
                        pts[k]++;
                    }
                    gf[k]=gf[k]+g2;
                    ga[k]=ga[k]+g1;
                    gp[k]=gp[k]+g2-g1;

                }
            }

            int h=i;
            if(exist1==0) h++;
            if(exist2==0) h++;
            if(exist1==0 && exist2==0)
            {
                playernamedata[i]=player1name;
                playernamedata[i+1]=player2name;
                games[i]=1;games[i+1]=1;
                if(g1>g2)
                {
                    wins[i]=1;
                    wins[i+1]=0;
                    lose[i]=0;
                    lose[i+1]=1;
                    draw[i]=0;
                    draw[i+1]=0;
                    pts[i]=3;
                    pts[i+1]=0;
                }
                else if(g1<g2)
                {
                    wins[i]=0;
                    wins[i+1]=1;
                    lose[i]=1;
                    lose[i+1]=0;
                    draw[i]=0;
                    draw[i+1]=0;
                    pts[i]=0;
                    pts[i+1]=3;

                }
                else if(g1==g2)
                {
                    wins[i]=0;
                    wins[i+1]=0;
                    lose[i]=0;
                    lose[i+1]=0;
                    draw[i]=1;
                    draw[i+1]=1;
                    pts[i]=1;
                    pts[i+1]=1;
                }

                gf[i]=g1;
                gf[i+1]=g2;
                ga[i]=g2;
                ga[i+1]=g1;
                gp[i]=g1-g2;
                gp[i+1]=g2-g1;

            }
            else if(exist1==0 && exist2==1)
            {
                playernamedata[i]=player1name;
                if(g1>g2)
                {
                    games[i]=1;
                    wins[i]=1;
                    lose[i]=0;
                    draw[i]=0;
                    gf[i]=g1;
                    ga[i]=g2;
                    gp[i]=g1-g2;
                    pts[i]=3;
                }
                else if(g1=g2)
                {
                    games[i]=1;
                    wins[i]=0;
                    lose[i]=0;
                    draw[i]=1;
                    gf[i]=g1;
                    ga[i]=g2;
                    gp[i]=g1-g2;
                    pts[i]=1;

                }
                else if(g2>g1)
                {
                    games[i]=1;
                    wins[i]=0;
                    lose[i]=1;
                    draw[i]=0;
                    gf[i]=g1;
                    ga[i]=g2;
                    gp[i]=g1-g2;
                    pts[i]=0;
                }

            }
            else if(exist1==1 && exist2==0)
            {
                playernamedata[i]=player2name;
                if(g2>g1)
                {
                    games[i]=1;
                    wins[i]=1;
                    lose[i]=0;
                    draw[i]=0;
                    gf[i]=g2;
                    ga[i]=g1;
                    gp[i]=g2-g1;
                    pts[i]=3;
                }
                else if(g2==g1)
                {
                    games[i]=1;
                    wins[i]=0;
                    lose[i]=0;
                    draw[i]=1;
                    gf[i]=g2;
                    ga[i]=g1;
                    gp[i]=g2-g1;
                    pts[i]=1;

                }
                else if(g1>g2)
                {
                    games[i]=1;
                    wins[i]=0;
                    lose[i]=1;
                    draw[i]=0;
                    gf[i]=g2;
                    ga[i]=g1;
                    gp[i]=g2-g1;
                    pts[i]=0;
                }

            }

            out.open("data.txt");
            if(out.good())
            {
                for(int j=0;j<h;j++)
                {
                    out<<playernamedata[j]<<' '<<games[j]<<' '<<wins[j]<<' '<<draw[j]<<' '<<lose[j]<<' '<<gf[j]<<' '<<ga[j]<<' '<<gp[j]<<' '<<pts[j]<<endl;
                }

                out<<"end";
                out.close();
            }






            return 0;
        }
        }

        if(timeplay<=10)
           finish=255;
        else
            finish=0;





        if(stop_ball)
        {
        if(yb+dyb+r>=floor )
        {
            dyb=-dyb+5;
        }
            yb+=dyb;

            dyb+=ayb;
            if (yb+r>floor)
            {
                stop_ball=false;
                yb=floor-r;
                dyb=0;
                ayb=1;
            }
        }
        if(xb+dxb+r>=xgoal1&& yb+dyb<ygoal-r)
        {
            dxb=-abs(dxb);
            xb+=dxb;
            collision=1;
        }
        if(xb+dxb-r<=xgoal2 && yb+dyb<ygoal-r)
        {
            dxb=abs(dxb);
            xb+=dxb;
            collision=1;
        }
        if(wall1)
            {
            if(counter_wall1!=0)
            {
                texture(m_renderer,xwall1,floor-h_net+20,"wall1.png",w_net,h_net);

                counter_wall1--;
                if(xb+dxb+r>=wall_barkhord1)
                {
                    xb=wall_barkhord1-r;


                    dxb=-dxb;
                    collision=1;
                }

            }
            else
                wall1=0;
            }
            if(wall2)
            {
            if(counter_wall2!=0)
            {
                texture(m_renderer,xwall2,floor-h_net+20,"wall2.png",w_net,h_net);

                counter_wall2--;
                if(xb+dxb-r<=wall_barkhord2)
                {
                    xb=wall_barkhord2+r;

                    dxb=-dxb;
                    collision=1;
                }

            }
            else
                wall2=0;
            }


        if(!tir1)
        if(xb+r>=xgoal1)
        {
            if(dyb>0)
            {
                if(yb<ygoal && yb+r>=ygoal)
                {
                    dxb=-dxb-5;
//                    xb=xgoal1-r;
                    if(dyb<=3)
                        dyb=5;
                    dyb=-dyb;

//                    yb=ygoal;
                    tir1=1;

                }
                else if(yb==ygoal)
                {
                    dxb=-dxb-5;
//                    xb=xgoal1-r;
//                    yb=ygoal;
                    tir1=1;
                }
                else if(yb>ygoal && yb-r<=ygoal)
                {

                    dyb=10;
                    dxb=5;
 //                    xb=xgoal1-r;
//                    yb=ygoal;
                    tir1=1;
                }



            }
            else if(dyb<=0)
           {
             if(yb<=ygoal && yb-r<=ygoal)
             {
//                 xb=xgoal1-r;
                 dxb=-dxb-5;
//                 yb=ygoal;
                 tir1=1;
             }
             else if(yb>ygoal && yb+r<=ygoal)
             {
//                 xb=xgoal1-r;
                    dyb=10;
                    dxb=-5;//                 yb=ygoal;
                 tir1=1;
             }
           }
           v_tir=tir1;
        }

        if(!tir2)
         if(xb-r<=xgoal2)
        {
            if(dyb>0)
            {
                if(yb<ygoal && yb+r>=ygoal)
                {
                    dxb=-dxb+5;
//                    xb=xgoal2+r;
                    if(dyb<=3)
                        dyb=5;
                    dyb=-dyb;
//                    yb=ygoal;
                    tir2=1;

                }
                else if(yb==ygoal)
                {
                    dxb=-dxb+5;
//                    xb=xgoal2+r;
//                    yb=ygoal;
                    tir2=1;
                }
                else if(yb>ygoal && yb-r<=ygoal)
                {
                    dyb=10;
                    dxb=5;
                    tir2=1;
                }

            }
            else if(dyb<=0)
           {
             if(yb<=ygoal && yb-r<=ygoal)
             {
//                 xb=xgoal2+r;
                 dxb=-dxb+5;
//                 yb=ygoal;
                 tir2=1;
             }
             else if(yb>ygoal && yb+r<=ygoal)
             {
//                  xb=xgoal2+r;
                    dyb=10;
                    dxb=-5;//                 yb=ygoal;
                 tir2=1;
             }
           }
           v_tir=tir2;
        }

    if(tir1 || tir2)
    {
        tir1=0;
        tir2=0;
    }
    if(pz1)
    {
        if(xb+r>=xz1 && xb-r<=xz1+100 && yb-r<=yz1+100 && yb+r>=yz1)
        {
            pz1=0;
            power1=0;
            power_start1=0;
        }

    }
    if(pz2)
    {
        if(xb+r>=xz2 && xb-r<=xz2+100 && yb-r<=yz2+100 && yb+r>=yz2)
        {
            pz2=0;
            power2=0;
            power_start2=0;
        }

    if(dxb<0)
        {
            if(dxb>=-15 && dxb<0)
            {
                dxb+=.1;
            }

//            else if(dxb>-90 && dxb<=-80)
//            {
//                dxb+=50;
//            }
//            else if(dxb> -120 && dxb<=-90)
//            {
//                dxb+=80;
//            }
//            else if(dxb<=-120 && dxb>-130)
//            {
//                dxb+=100;
//            }
//            else if(dxb<=-130)
//            {
//                dxb+=120;
//            }
            else
                dxb+=.25;
            if(dxb>=0)
            {
                dxb=0;
//                if(dyb!=0){
//                    dxb-=1;
//                    xb+=dxb;
//                    d_xb=dxb;
//                }
            }

        }
    else if(dxb>0)
        {
            if(dxb<=15 && dxb>0)
            {
                dxb-=.1;
            }

//            else if(dxb>=80 && dxb<90)
//            {
//                dxb-=50;
//            }
//            else if( dxb<120  && dxb>=90)
//            {
//                dxb-=80;
//            }
//            else if(dxb>=120 && dxb<130)
//            {
//                dxb-=100;
//            }
//            else if(dxb>=130)
//            {
//                dxb-=120;
//            }
            else
                dxb-=.25;
            if(dxb<=0)
            {
                dxb=0;
//                if(dyb!=0){
//                   dxb+=1;
//                   xb+=dxb;
//                   d_xb=dxb;
//                }
            }
        }
    }
    if(!tir1 && !tir2)
    {
        xb+=dxb;
    }
      if( yb-r>ygoal){
    if(xb-r>=xgoal1)
        {
            if(xb+r>=xgoal1+70)
                xb=xgoal1+70-r;
     goalshod=1;
    texture(m_renderer,W/5,H/7,"goalshod.png",3*W/5,H/2);
SDL_RenderPresent(m_renderer);

     dxb=15;
     g2++;
    }
else if(xb+r<=xgoal2 )
    {
    if(xb-r<=xgoal2-70)
        xb=xgoal2-70+r;

    goalshod=1;
     dxb=-15;
    texture(m_renderer,W/5,H/7,"goalshod.png",3*W/5,H/2);
SDL_RenderPresent(m_renderer);

     g1++;

    }
    }

        if(ball){

             if(dxb==0 && dyb==0)
             {
                texture(m_renderer,xb-r,yb-r,"ball1.png",2*r,2*r);
                round_ball='1';
             }
             else
             {

                 string si="ball";
                 si.push_back(round_ball);
                 si+=".png";
                 if(dxb<0){
                  if( dxb*d_xb>0)
                 {
                    texture(m_renderer,xb-r,yb-r,si,2*r,2*r);

                 }
                 else if(dxb*d_xb<=0){
                    round_ball='1';
                    texture(m_renderer,xb-r,yb-r,"ball1.png",2*r,2*r);
                 }
                 round_ball++;
                 }



                 else
                 {
                     if(dxb*d_xb>0){
                     if(round_ball=='1' || round_ball=='3')
                            texture(m_renderer,xb-r,yb-r,si,2*r,2*r);
                     else if(round_ball=='2')
                            texture(m_renderer,xb-r,yb-r,"ball4.png",2*r,2*r);
                     else if(round_ball=='4')
                            texture(m_renderer,xb-r,yb-r,"ball2.png",2*r,2*r);
                     }
                     else if(dxb*d_xb<=0)
                    {
                        round_ball='3';
                        texture(m_renderer,xb-r,yb-r,"ball3.png",2*r,2*r);
                    }

                   round_ball++;

                 }

                if(round_ball>'4')
                    round_ball='1';
             }
             d_xb=dxb;

        }
    if(g2/10==0){
    switch(g2)
            {
            case 0:
                texture(m_renderer,xpower-90-wr,ypower+70,"0 b.png",wr,wr);
             break;
            case 1:
                texture(m_renderer,xpower-90-wr,ypower+70,"1 b.png",wr,wr);
             break;
            case 2:
                texture(m_renderer,xpower-90-wr,ypower+70,"2 b.png",wr,wr);
             break;
            case 3:
                texture(m_renderer,xpower-90-wr,ypower+70,"3 b.png",wr,wr);
             break;
            case 4:
                texture(m_renderer,xpower-90-wr,ypower+70,"4 b.png",wr,wr);
             break;
            case 5:
                texture(m_renderer,xpower-90-wr,ypower+70,"5 b.png",wr,wr);
             break;
            case 6:
                texture(m_renderer,xpower-90-wr,ypower+70,"6 b.png",wr,wr);
             break;
            case 7:
                texture(m_renderer,xpower-90-wr,ypower+70,"7 b.png",wr,wr);
             break;
            case 8:
                texture(m_renderer,xpower-90-wr,ypower+70,"8 b.png",wr,wr);
             break;
            case 9:
                texture(m_renderer,xpower-90-wr,ypower+70,"9 b.png",wr,wr);
             break;
            }
    }
    else{
           switch(g2/10)
            {

            case 1:
                texture(m_renderer,xpower-90-2*wr,ypower+70,"1 b.png",wr,wr);
             break;
            case 2:
                texture(m_renderer,xpower-90-2*wr,ypower+70,"2 b.png",wr,wr);
             break;
            case 3:
                texture(m_renderer,xpower-90-2*wr,ypower+70,"3 b.png",wr,wr);
             break;
            case 4:
                texture(m_renderer,xpower-90-2*wr,ypower+70,"4 b.png",wr,wr);
             break;
            case 5:
                texture(m_renderer,xpower-90-2*wr,ypower+70,"5 b.png",wr,wr);
             break;
            case 6:
                texture(m_renderer,xpower-90-2*wr,ypower+70,"6 b.png",wr,wr);
             break;
            case 7:
                texture(m_renderer,xpower-90-2*wr,ypower+70,"7 b.png",wr,wr);
             break;
            case 8:
                texture(m_renderer,xpower-90-2*wr,ypower+70,"8 b.png",wr,wr);
             break;
            case 9:
                texture(m_renderer,xpower-90-2*wr,ypower+70,"9 b.png",wr,wr);
             break;
            }
            switch(g1%10)
            {
            case 0:
                texture(m_renderer,xpower-90-wr,ypower+70,"0 b.png",wr,wr);
             break;
            case 1:
                texture(m_renderer,xpower-90-wr,ypower+70,"1 b.png",wr,wr);
             break;
            case 2:
                texture(m_renderer,xpower-90-wr,ypower+70,"2 b.png",wr,wr);
             break;
            case 3:
                texture(m_renderer,xpower-90-wr,ypower+70,"3 b.png",wr,wr);
             break;
            case 4:
                texture(m_renderer,xpower-90-wr,ypower+70,"4 b.png",wr,wr);
             break;
            case 5:
                texture(m_renderer,xpower-90-wr,ypower+70,"5 b.png",wr,wr);
             break;
            case 6:
                texture(m_renderer,xpower-90-wr,ypower+70,"6 b.png",wr,wr);
             break;
            case 7:
                texture(m_renderer,xpower-90-wr,ypower+70,"7 b.png",wr,wr);
             break;
            case 8:
                texture(m_renderer,xpower-90-wr,ypower+70,"8 b.png",wr,wr);
             break;
            case 9:
                texture(m_renderer,xpower-90-wr,ypower+70,"9 b.png",wr,wr);
             break;
            }
      }
    if(g1/10==0){
    switch(g1)
            {
            case 0:
                texture(m_renderer,xpower-90-wr,ypower,"0 r.png",wr,wr);
             break;
            case 1:
                texture(m_renderer,xpower-90-wr,ypower,"1 r.png",wr,wr);
             break;
            case 2:
                texture(m_renderer,xpower-90-wr,ypower,"2 r.png",wr,wr);
             break;
            case 3:
                texture(m_renderer,xpower-90-wr,ypower,"3 r.png",wr,wr);
             break;
            case 4:
                texture(m_renderer,xpower-90-wr,ypower,"4 r.png",wr,wr);
             break;
            case 5:
                texture(m_renderer,xpower-90-wr,ypower,"5 r.png",wr,wr);
             break;
            case 6:
                texture(m_renderer,xpower-90-wr,ypower,"6 r.png",wr,wr);
             break;
            case 7:
                texture(m_renderer,xpower-90-wr,ypower,"7 r.png",wr,wr);
             break;
            case 8:
                texture(m_renderer,xpower-90-wr,ypower,"8 r.png",wr,wr);
             break;
            case 9:
                texture(m_renderer,xpower-90-wr,ypower,"9 r.png",wr,wr);
             break;
            }
    }
    else{
            switch(g1/10)
            {
            case 1:
                texture(m_renderer,xpower-90-2*wr,ypower,"1 r.png",wr,wr);
             break;
            case 2:
                texture(m_renderer,xpower-90-2*wr,ypower,"2 r.png",wr,wr);
             break;
            case 3:
                texture(m_renderer,xpower-90-2*wr,ypower,"3 r.png",wr,wr);
             break;
            case 4:
                texture(m_renderer,xpower-90-2*wr,ypower,"4 r.png",wr,wr);
             break;
            case 5:
                texture(m_renderer,xpower-90-2*wr,ypower,"5 r.png",wr,wr);
             break;
            case 6:
                texture(m_renderer,xpower-90-2*wr,ypower,"6 r.png",wr,wr);
             break;
            case 7:
                texture(m_renderer,xpower-90-2*wr,ypower,"7 r.png",wr,wr);
             break;
            case 8:
                texture(m_renderer,xpower-90-2*wr,ypower,"8 r.png",wr,wr);
             break;
            case 9:
                texture(m_renderer,xpower-90-2*wr,ypower,"9 r.png",wr,wr);
             break;
            }
        switch(g1%10)
            {
            case 0:
                texture(m_renderer,xpower-90-wr,ypower,"0 r.png",wr,wr);
             break;
            case 1:
                texture(m_renderer,xpower-90-wr,ypower,"1 r.png",wr,wr);
             break;
            case 2:
                texture(m_renderer,xpower-90-wr,ypower,"2 r.png",wr,wr);
             break;
            case 3:
                texture(m_renderer,xpower-90-wr,ypower,"3 r.png",wr,wr);
             break;
            case 4:
                texture(m_renderer,xpower-90-wr,ypower,"4 r.png",wr,wr);
             break;
            case 5:
                texture(m_renderer,xpower-90-wr,ypower,"5 r.png",wr,wr);
             break;
            case 6:
                texture(m_renderer,xpower-90-wr,ypower,"6 r.png",wr,wr);
             break;
            case 7:
                texture(m_renderer,xpower-90-wr,ypower,"7 r.png",wr,wr);
             break;
            case 8:
                texture(m_renderer,xpower-90-wr,ypower,"8 r.png",wr,wr);
             break;
            case 9:
                texture(m_renderer,xpower-90-wr,ypower,"9 r.png",wr,wr);
             break;
            }

      }
      if(!goalshod)
      {
        if(tball!=0)
        {
            tball--;
            if(tball==0)
                ball=1;
        }
        if(yb+r>=floor-5&& yp1<floor-hp && yp1+hp+2*r>=floor-5 && dyp1>0)
        {
            if(xb+r>=xp1+10 && xb-r<=xp1+wp1-10){
                yb=floor-r;
                counter1=50;
                vfall=1;
                xp1=xb+r+3;
                if(xp1+hp>=xgoal1+70)
                {
                    xp1=xgoal1+70-hp;
                    xb=xp1-r-3;

                }
            }
        }
        if(counter1>=0)
        {
            if(tripple_clone1){
                tripple_clone1=0;
                wp1=wp;
                xp1=xb+r+3;

            }
            fall1=1;
            counter1--;

            if(!kick_fire2 && counter1>0){
            dxb=0;
            dyb=0;
            }
            if(counter1==0){
                kick_fire2=0;
                fall1=0;
            }
            int xo=xp1+wp1-4-head/2;
            int yo=floor-wp1-40;
            texture(m_renderer,xp1,floor-wp1,f1,hp,wp1);
            x_sargardan=xo+rRotX*cos(theta1);
            y_sargardan=yo-rRotY*sin(theta1);
            if(theta1>6.2831853)
                theta1-=6.2831853;
            if(theta1>=0 && theta1<=3.14159265)
            {
            texture(m_renderer,x_sargardan,y_sargardan,"sargardan12.png",w_sargardan,h_sargardan);
            }
            if(theta1<=6.2831853 && theta1>=3.14159265)
            {
            texture(m_renderer,x_sargardan,y_sargardan,"sargardan11.png",w_sargardan,h_sargardan);
            }             theta1+=.3;
        }
        if(yb+r>=floor-5 && yp2<floor-hp && yp2+hp+2*r>=floor-5 && dyp2>0)
        {
            if(xb+r>=xp2+10 && xb-r<=xp2+wp2-10){
                yb=floor-r;
                counter2=50;
                vfall=1;
                xp2=xb-r-hp-3;
                if(xp2<=xgoal2-70)
                {
                    xp2=xgoal2-70;
                    xb=xp2+wp2+r+3;

                }
            }
        }
        if(counter2>=0)
        {
            if(tripple_clone2){
                tripple_clone2=0;
                wp2=wp;
                xp2=xb-r-wp2-3;
            }
            fall2=1;
            counter2--;
            if(!kick_fire1 && counter2>0){
            dxb=0;
            dyb=0;
            }
            if(counter2==0){
                kick_fire1=0;
                fall2=0;

            }


            texture(m_renderer,xp2,floor-wp,f2,hp,wp2);
            int xo=xp2+4+head/2;
            int yo=floor-wp2-40;
            x_sargardan=xo+rRotX*cos(theta2);
            y_sargardan=yo-rRotY*sin(theta2);
            if(theta2>6.2831853)
                theta2-=6.2831853;
            if(theta2>=0 && theta2<=3.14159265)
            {
            texture(m_renderer,x_sargardan,y_sargardan,"sargardan12.png",w_sargardan,h_sargardan);
            }
            if(theta2<=6.2831853 && theta2>=3.14159265)
            {
            texture(m_renderer,x_sargardan,y_sargardan,"sargardan11.png",w_sargardan,h_sargardan);
            }

            theta2+=.3;
        }


//          if(e->type==SDL_KEYDOWN)
//            {
//                switch(e->key.keysym.sym)
//                {
        SDL_PumpEvents();
        const Uint8 *keystates = SDL_GetKeyboardState(NULL);
                    if(keystates[SDL_GetScancodeFromKey(SDLK_UP)]) {
                            if(!fall1){
                    if(!flag1)
                    {
                        flag1=1;
                        dyp1=-15;

                    }
                    }
                    }

                     if(keystates[SDL_GetScancodeFromKey(SDLK_RIGHT)]){
                        if(!fall1){
                        if(xp1+wp1+10>=xgoal1+70){
                            xp1=xgoal1+70-wp1;
                        }
                        else
                           xp1+=10;
                     }
                     }

                     if(keystates[SDL_GetScancodeFromKey(SDLK_LEFT)]){
                        if(!fall1)
                        {
                            if(xp1-10<0)
                            xp1=0;
                        else
                           xp1-=10;
                    }
                     }

                    if(keystates[SDL_GetScancodeFromKey(SDLK_w)]){
                            if(!fall2){
                        if(!flag2)
                        {
                        flag2=1;
                        dyp2=-15;

                        }
                    }
                    }


                    if(keystates[SDL_GetScancodeFromKey(SDLK_d)]){
                     if(!fall2)
                     {
                         if(xp2+wp2+10>=W)
                            xp2=W-wp2;
                        else
                           xp2+=10;
                    }
                    }

                     if(keystates[SDL_GetScancodeFromKey(SDLK_a)]){
                     if(!fall2)
                     {
                         if(xp2-10<=xgoal2-70)
                            xp2=xgoal2-70;
                        else
                           xp2-=10;
                    }
                     }

                    if(keystates[SDL_GetScancodeFromKey(SDLK_m)]){
                      if(!fall1)
                      {
                        shoot_zamini1=1;
//                        if(!tripple_clone1){
                        texture(m_renderer,xp1-l,yp1,p12,wp+f,hp);
//                        }
                     if((xb+r+5>=xp1)&&(xb-r<=xp1)){
                        if(yb>=yp1+head && yb<=hp+yp1 )
                            {
                               dyb=-10;
                               dxb=-30;
                               stop_ball=1;
                               shoot=1;

                            }
                     }
                     }
                    }


                    if(keystates[SDL_GetScancodeFromKey(SDLK_DOWN)]){
                     if(!fall1)
                     {
                    shoot_havaee1=1;

                    if(!tripple_clone1){
                    texture(m_renderer,xp1,yp1,p13,wp1,hp);
                    }
                    if((xb+r+5>=xp1)&&(xb-r<=xp1))
                    {
                       if(yb>=yp1+head && yb<=hp+yp1 )
                            {
                                dyb=-28;
                                ayb=1.6;

                                dxb=-30;
                                stop_ball=1;
                                shoot=1;
                            }
                        }
                    }
                    }
                     if(keystates[SDL_GetScancodeFromKey(SDLK_z)]){
                     if(!fall2)
                     {
                        shoot_havaee2=1;

                         if(!tripple_clone2){
                        texture(m_renderer,xp2,yp2,p23,wp2,hp);

                         }

                      if((xb+r>=xp2+wp2)&&(xb-r-5<=xp2+wp2))
                        {
                        if(yb>=yp2+head && yb<=hp+yp2 )
                        {
                                    dyb=-28;
                                    ayb=1.6;
                                    dxb=30;
                                    stop_ball=1;
                                    shoot=1;
                        }
                        }
                      }
                     }
                     if(keystates[SDL_GetScancodeFromKey(SDLK_x)]){
                  if(!fall2){
                    shoot_zamini2=1;

                    if(!tripple_clone2){
                  texture(m_renderer,xp2,yp2,p22,wp+f,hp);
                    }
                   if((xb+r>=xp2+wp2)&&(xb-r-20<=xp2+wp2)){
                        if(yb>=yp2+head && yb<=hp+yp2 )
                        {
                            dyb=-10;
                            dxb=30;
                            stop_ball=1;
                            shoot=1;

                        }
                   }
                   }
                    }
                     if(keystates[SDL_GetScancodeFromKey(SDLK_p)]){
                    if(kfa && !power_start1){
                    if(!fall1){
                     if((xb+r+5>=xp1)&&(xb-r<=xp1)){
                        if(yb>=yp1+head && yb<=hp+yp1)
                            {
                                texture(m_renderer,xp1-l,yp1,p12,wp1+f,hp);
                               xb-=20;
                               dxb=-40;
                               stop_ball=1;
                               kick_fire1=1;
                               b1=1;
                               power_start1=1;
                               shoot=1;

                            }

                     }
                    }
                    }
                     }
                    if(keystates[SDL_GetScancodeFromKey(SDLK_o)]){
                    if(kfb && !power_start2)
                    {
                    if(!fall2){
                     if((xb+r>=xp2+wp2)&&(xb-r-5<=xp2+wp2)){
                        if(yb>=yp2+head && yb<=hp+yp2)
                            {
                                texture(m_renderer,xp2,yp2,p22,wp2+f,hp);

                               dxb=40;
                               xb+=20;
                               stop_ball=1;
                               kick_fire2=1;

                               b2=1;
                               power_start2=1;
                               shoot=1;

                            }

                     }
                    }
                    }
                    }
                     if(keystates[SDL_GetScancodeFromKey(SDLK_l)])
                    {
                     if(hfa && !power_start1)
                     {
                    if(!fall1)
                     {
                     if(yb<=yp1-hp+70)
                     {
                         if(xb+r>=xp1-20 && xb-r<xp1+20 )
                         {

                             yp1=yb-r-10;
                             head_fire1=1;
                             dxb=-dxb;
                             xp1=xb+r-fargh1/2;
                             texture(m_renderer,xp1,yp1,h1,wp1,hp);
                             b1=1;
                             power_start1=1;
                         }
                     }
                     }
                     }
                     }
                    if(keystates[SDL_GetScancodeFromKey(SDLK_k)]){
                    if(hfb && !power_start2){
                    if(!fall2){
                     if(yb<=yp2-hp+70)
                     {
                         if(xb+r>=xp2+wp2-20 && xb-r<xp2+wp2+20 )
                         {

                             yp2=yb-r-10;
                             head_fire2=1;
                             dxb=-dxb;
                             xp2=xb+r-fargh2/2-wp2;
                             texture(m_renderer,xp2,yp2,h2,wp1,hp);
                             b2=1;
                             power_start2=1;
                         }
                     }
                     }
                    }
                    }

                     if(keystates[SDL_GetScancodeFromKey(SDLK_t)]){
                        if(!power_start1 && tca)
                        {
                        if(!fall1){
                        tripple_clone1=1;
                        power1=1;
                        power_start1=1;
                        }
                        }
                    }
                     if(keystates[SDL_GetScancodeFromKey(SDLK_r)]){
                    if(tcb && !power_start2)
                    {
                        if(!fall2){
                        tripple_clone2=1;
                        power2=1;
                        power_start2=1;
                        }
                    }
                     }
                     if(keystates[SDL_GetScancodeFromKey(SDLK_i)]){
                    if(iba && !power_start1){
                    if(!fall1){
                    if((xb+r+5>=xp1)&&(xb-r<=xp1)){
                    if(yb+r>=yp1 && yb-r<=yp1+hp){
                        ball=0;
                        tball=200;
                        dxb=-30;
                        power_start1=1;
                    }
                     }
                     }
                     }
                     }


                     if(keystates[SDL_GetScancodeFromKey(SDLK_u)]){
                            if(ibb && !power_start2)
                        {
                        if(!fall2){
                        if((xb+r>=xp2+wp2)&&(xb-r-5<=xp2+wp2)){
                        if(yb+r>=yp1 && yb-r<=yp1+hp){
                        ball=0;
                        tball=200;
                        dxb=30;
                        power_start2=1;
                        }
                        }

                     }
                     }
                     }

                    if(keystates[SDL_GetScancodeFromKey(SDLK_h)])
                        {
                            if(pua && !power_start1)
                            {


                            if(!fall1){
                            if(xp1-xp2-wp2<=15){
                                punch1=1;
                                xp2-=10;
                                texture(m_renderer,xp1,yp2,"punch 1.png",wp,70);
                                power_start1=1;
                                v_punch=1;
                        }
                        }
                        }
                        }

                     if(keystates[SDL_GetScancodeFromKey(SDLK_g)])
                        {
                            if(pub && !power_start2){
                            if(!fall2){
                            if(xp1-xp2-wp2<=15){
                                punch2=1;
                                xp1+=20;
                                texture(m_renderer,xp2,yp2,"punch 2.png",wp,70);
                                power_start2=1;
                                v_punch=1;
                            }
                            }
                            }

                        }

                     if(keystates[SDL_GetScancodeFromKey(SDLK_n)])
                     {
                         if(!power_start1 && swa){
                         if(!fall1){
                         wall1=1;
                         counter_wall1=200;
                         power_start1=1;
                         }
                         }

                     }

                     if(keystates[SDL_GetScancodeFromKey(SDLK_b)])
                     {
                         if(!power_start2 && swb)
                         {

                         if(!fall2){
                         wall2=1;
                         counter_wall2=200;
                         power_start2=1;
                         }
                         }
                     }



                     if(keystates[SDL_GetScancodeFromKey(SDLK_SPACE)]){

                        SDL_DestroyWindow( m_window );
                        SDL_DestroyRenderer( m_renderer );
                        IMG_Quit();
	                    SDL_Quit();
                        return 0;
                    }
      }
            texture(m_renderer,10,10,"pause.png",50,50);
        SDL_PollEvent(e);
         if(e->type==SDL_MOUSEBUTTONDOWN)
            {
             if((e->button.button==SDL_BUTTON_LEFT))
            {
                int x0=e->motion.x;
                int y0=e->motion.y;
                if(x0<=60 && x0>=10 && y0<=60 && y0>=10)
                   {
                    pause=0;
                    time_pause1=clock();

//                    Mix_PlayMusic(vpause,-1);
                   }
            }
            }
            e->type=0;



//            if(xp1+wp>=wall_right)
//            {
//                xp1=wall_right-wp;
//            }
//            if(xp2<=wall_left)
//            {
//                xp2=wall_left;
//            }
        if(!goalshod)
        {


        if(pz1)
        {
            if(xp1<=xz1+100 && xp1+wp1>=xz1 && yp1<=yz1+100 && yp1+hp>=yz1)
            {
                pz1=0;
                power_start1=0;
                power1=0;
            }

        }
        if(pz2)
        {
            if(xp2<=xz2+100 && xp2+wp2>=xz2 && yp2<=yz2+100 && yp2+hp>=yz2)
            {
                pz2=0;
                power_start2=0;
                power2=0;
            }

        }
        if(wall1){
        if(xp1+wp1>=wall_barkhord1)
        {
            xp1=wall_barkhord1-wp1;
        }
        }
        if(wall2){
        if(xp2<=wall_barkhord2)
        {
            xp2=wall_barkhord2;
        }
        }
        if(head_fire1)
        {
            if(dxb<=0){

            dxb=(-xb)/ax;
            if(dxb>=-50)
                dxb=-50;
            if(dxb<=-80)
                dxb=-80;

            dyb=(floor-100-yb)/ay;
            }
            else
            {
                head_fire1=0;
            }
            if(yp1+hp>=floor)
            {
                yp1=floor-hp;
            }
            else
            {
                yp1+=20;
            }
            if(xb-r<=xp2+wp2 && xb+r>=xp2 && fall2==0 && yb+r>=yp2)
            {
                counter2=100;
                kick_fire1=1;
            }
        }
        if(head_fire2)
        {
            if(dxb>=0){

            dxb=(W-xb)/ax;
            if(dxb<50)
                dxb=50;
            if(dxb>80)
                dxb=80;
            dyb=(floor-100-yb)/ay;
            }
            else
            {
                head_fire2=0;
            }
            if(yp2+hp>=floor)
            {
                yp2=floor-hp;
            }
            else
            {
                yp2+=20;
            }
            if(xb-r<=xp1+wp1 && xb+r>=xp1 && fall1==0 && yb+r>=yp1)
            {
                counter1=100;
                kick_fire2=1;
            }
        }
        if(!fall2){
        if(kick_fire1)
        {

            if(xb-r<=xp2+wp)
            {
                dxb=-dxb;
                counter2=200;
                vfall=1;
                if(xp2-200<xgoal2-70)
                    xp2=xgoal2-70;
                else
                    xp2-=200;
                fall2=1;
            }

        }
        }
        if(!fall1){
        if(kick_fire2)
        {

            if(xb+r>=xp1)
            {
                dxb=-dxb;
                counter1=200;
                vfall=1;
                if(xp1+wp1+200>xgoal1+70)
                    xp1=xgoal1+70-wp1;
                else
                    xp1+=200;
                fall1=1;
            }

        }
        }
        if(flag1)
        {
            yp1+=dyp1;
            dyp1++;
            if(yp1>=floor-hp)
            {
                flag1=0;
                yp1=floor-hp;
            }
        }
        if(flag2)
        {
            yp2+=dyp2;
            dyp2++;
            if(yp2>=floor-hp)
            {
                flag2=0;
                yp2=floor-hp;
            }
        }
        if(tripple_clone1==0)
        {
            counter3=200;
        }
        if(tripple_clone2==0)
        {
            counter4=200;
        }
        if(tripple_clone1)
        {
            wp1=3*wp;
            if(counter3==200)
            {
            if(xp1<=xp2+wp2)
            {
                xp1=xp2+wp2+10;
            }
            if(xp1+wp1>=xgoal1+70)
            {
                xp1=xgoal1+70-wp1;
            }

            if(yb-r>=yp1){
            if((xb+r>=xp1) && (xb-r<=xp1+wp1))
            {
                if(xp1>=(xp2+wp2+2*r+10))
                {
                    xb=xp1-r-3;
                    dxb=0;
                }
                else
                {
                    yb-=151;
                    dyb=-7;
                    stop_ball=1;
                }


            }
            }

            }
            if(xp1<xp2+wp2)
            {
                    xp1=xp2+wp2+10;
                    counter3=0;
                    power1=1000;
                    power_start1=0;
            }
            else if(xp1+wp1>xgoal1+70)
                 {
                     wp1=wp;
                    xp1=xgoal1+70-wp1;

                        counter3=0;
                    power1=1000;
                    power_start1=0;
                 }

            if(counter3!=0)
           {
            xp12=xp1+wp;
            xp13=xp1+2*wp;

            if(!shoot_havaee1 && !shoot_zamini1){
            texture(m_renderer,xp1,yp1,p11,wp,hp);
            texture(m_renderer,xp12,yp1,p11,wp,hp);
            texture(m_renderer,xp13,yp1,p11,wp,hp);
           }
           if(shoot_havaee1)
           {
            texture(m_renderer,xp1,yp1,p13,wp,hp);
            texture(m_renderer,xp12,yp1,p13,wp,hp);
            texture(m_renderer,xp13,yp1,p13,wp,hp);

           }
           if(shoot_zamini1)
           {

            texture(m_renderer,xp12,yp1,p11,wp,hp);
            texture(m_renderer,xp13,yp1,p11,wp,hp);

           }
           }
            counter3--;
            if(counter3<=0){
            tripple_clone1=0;
            wp1=wp;
            counter3=200;

            }

        }
        if(tripple_clone2)

        {
            wp2=3*wp;
            if(counter4==200)
            {
                xp2-=2*wp-10;

            if(xp2<=xgoal2-70)
            {
                xp2=xgoal2-70;

            }
            if(xp2+wp2>=xp1)
            {
                xp2=xp1-wp2-10;

            }
            if(yb-r>=yp2){
            if((xb+r>=xp2 )&& (xb-r<=xp2+wp2))
            {
                if(xp1>=(xp2+wp2+2*r+10))

                {
                    xb=xp2+wp2+r+3;
                    dxb=0;
                }
                else
                {
                    yb-=151;
                    dyb=-7;
                    stop_ball=1;
                }

            }

            }



            }
            if(xp2+wp2>xp1)
            {
                wp2=wp;
                        xp2=xp1-wp2-10;
                        counter4=0;
                        power2=1000;
                        power_start2=0;
            }
            if(xp2<xgoal2-70)
            {
                        xp2=xgoal2-70;
                        counter4=0;
                        power2=1000;
                        power_start2=0;
            }

        if(counter4!=0)
           {
            xp22=xp2+wp;
            xp23=xp2+2*wp;
            if(!shoot_havaee2 && !shoot_zamini2){
            texture(m_renderer,xp2,yp2,p21,wp,hp);
            texture(m_renderer,xp22,yp2,p21,wp,hp);
            texture(m_renderer,xp23,yp2,p21,wp,hp);
           }
           if(shoot_havaee2)
           {
            texture(m_renderer,xp2,yp2,p23,wp,hp);
            texture(m_renderer,xp22,yp2,p23,wp,hp);
            texture(m_renderer,xp23,yp2,p23,wp,hp);

           }
           if(shoot_zamini2)
           {
            texture(m_renderer,xp23,yp2,p22,wp+f,hp);

            texture(m_renderer,xp22,yp2,p21,wp,hp);
            texture(m_renderer,xp2,yp2,p21,wp,hp);

           }
           }
            counter4--;
            if(counter4<=0)
            {
            tripple_clone2=0;
            wp2=wp;
            counter4=200;
            }
        }
        if(punch1)
        {
            if(counter2<=0)
            {
                counter2=100;
                vfall=1;
                kick_fire1=1;
            }
        }
        if(punch2)
        {
            if(counter1<=0)
            {
                counter1=100;
                vfall=1;
                kick_fire2=1;
            }
        }
        if(xp1-xp2-wp2<=3)
        {
            if(xp2>t)
                xp2=t;
            xp1=xp2+wp2+3;
            t=xp2;
        }
        else
            t=W;
        }
        if(!shoot_havaee1 && !shoot_zamini1 && !fall1 && !b1 && !punch1  ){
                texture(m_renderer,xp1,yp1,p11,wp,hp);
        }
        if(!shoot_havaee2 && !shoot_zamini2 && !fall2 && !b2 && !punch2){
                texture(m_renderer,xp2,yp2,p21,wp,hp);
        }
        if(!goalshod)
        {



        if(yb+r>=yp1+5 && yb<=yp1+nose)
            {
                if(xb+r>=xp1+fargh1/2 && xb-r<=xp1+fargh1/2)
                {
                    if(dyb>0)
                    {
                        dyb+=2;
                        if(dyb>=12)
                            dyb=12;
                    }
                    if(dyb<0)
                    {
                        dyb-=2;
                        if(dyb<=-12)
                            dyb=-12;

                    }
                     dxb=-dxb;
                     if(dxb>=-15)
                        dxb=-15;
                    if(dxb<=-25)
                            dxb=-25;
                }
            }
            else if(yb>yp1+nose && yb<yp1+head)
            {
                if(xb+r>=xp1 && xb-r<=xp1)
                {
                    dxb=-dxb;
                    if(dxb>=-15)
                         dxb=-15;
                    if(dxb<=-25)
                        dxb=-25;

                }

            }
            else if(yb>=yp1+head && yb<=yp1+hp)
            {
                if(fall1)
                {
                    if(xb+r>=xp1 && xb-r<=xp1)
                        dxb=-dxb;

                }
                else if(shoot_zamini1==0 && shoot_havaee1==0)
                {
                    if(xb+r>=xp1+5 && xb-r<=xp1+5)
                    {
                        if(dxb<=15)
                            dxb=15;
                        if(dxb>=25)
                            dxb=25;


                        dxb=-dxb;


                    }

                }
            }


             else if(yb>yp1+hp && yb-r<=yp1+hp-5)
             {
//                if(shoot_zamini1==0 && shoot_havaee1==0){
                    if(xb+r>=xp1 && xb-r<=xp1)
                    {
                        dxb=-7;
                    }
             }
        if(dyb>=0){
        if(xb>xp1+fargh && xb-r<=xp1+wp1-25)
        {
            if((yb+r>=yp1)&&(yb-r<=yp1))
            {
                yb=yp1-r;
                if(dyb>=0){
                if(dyb<=10)
                    dyb=10;
                dyb=-dyb;
                }
                stop_ball=1;
                if(xp1>helpme1)
                    dxb=12;
                else if(xp1<helpme1)
                    dxb=-12;
            }
        }
        }
        else if(dyb<0)
            {
                if(xb>xp1 && xb<=xp1+wp1){

                if(yb-r<=yp1+hp && yb+r>=yp1+hp){
                yb=yp1+hp+r;
                dyb=-dyb;
                stop_ball=1;
                }
                }
            }


//        if((xb+r>=xp1)&&(xb-r<=xp1))
//        {
//            if(yb>=yp1 && yb+r<yp1+head)
//             {
//               dyb=-10;
//               dxb=-dxb;
//               stop_ball=1;
//             }
//        }
//        if(dxb==0){
//        if((xb+r>=xp1+3)&&(xb-r<=xp1)){
//
//        if(shoot_havaee1==0 && shoot_zamini1==0)
//        {
//            if(yb+r>=yp1+head  &&  yb+r<=yp1+hp)
//            {
//                dxb=-3;
//            }
//        }
//        }
//      }

//        if(dxb>0){
//        if((xb+r>=xp1+10)&&(xb-r<=xp1)){
//
//        if(shoot_havaee1==0 && shoot_zamini1==0)
//        {
//            if(yb+r>=yp1+head  &&  yb+r<=yp1+hp)
//            {
//                dxb=-dxb;
//            }
//        }
//
//        }
//        }
            helpme1=xp1;


            if(yb+r>=yp2+5 && yb<=yp2+nose)
            {
                if(xb+r>=xp2+wp2-fargh2/2 && xb-r<=xp2+wp2-fargh2/2)
                {
                    if(dyb>0)
                    {
                        dyb+=2;
                        if(dyb>=12)
                            dyb=12;

                    }
                    if(dyb<0)
                    {
                        dyb-=2;
                        if(dyb<=-12)
                            dyb=-12;

                    }
                    dxb=-dxb;
                    if(dxb<=15)
                    {
                        dxb=15;
                    }
                    if(dxb>=25)
                        dxb=25;


                }
            }
            else if(yb>yp2+nose && yb<=yp2+head)
            {
                if(xb+r>=xp2+wp2 && xb-r<=xp2+wp2)
                {
                    dxb=-dxb;
                    if(dxb<=15)
                    {
                        dxb=15;
                    }
                    if(dxb>=25)
                    {
                        dxb=25;
                    }
                }

            }
            else if(yb>=yp2+head && yb<=yp2+hp)
            {
                if(fall2)
                {
                    if(xb+r>=xp2+wp2 && xb-r<=xp2+wp2)
                        dxb=-dxb;
                }
                else if(shoot_zamini2==0 && shoot_havaee2==0)
                {
                    if(xb+r>=xp2+wp2-5 && xb-r<=xp2+wp2-5)
                    {
                        if(dxb>=-15)
                            dxb=-15;
                        if(dxb<=-25)
                            dxb=-25;

                        dxb=-dxb;


                    }

                }
            }
            else if(yb>yp2+hp && yb-r<=yp2+hp-5)
             {
//                if(shoot_zamini1==0 && shoot_havaee1==0){
                    if(xb+r>=xp2+wp2 && xb-r<=xp2+wp2)
                    {
                        dxb=7;
                    }
             }


        if(dyb>=0){
        if(xb<xp2+wp2-fargh && xb-r>=xp2+25)
        {
            if((yb+r>=yp2)&&(yb-r<=yp2))
            {
                yb=yp2-r;
                if(dyb>=0){
                if(dyb<=10)
                    dyb=10;
                dyb=-dyb;
                }

                if(xp2<helpme2)
                    dxb=-12;
                else if(helpme2<xp2)
                    dxb=12;

                stop_ball=1;
            }
        }
        }
        else if(dyb<0)
            {
                if(xb>xp2 && xb<=xp2+wp2){

                if(yb-r<=yp2+hp && yb+r>=yp2+hp){
                yb=yp2+hp+r;
                dyb=-dyb;
                stop_ball=1;
                }
                }
            }
        helpme2=xp2;
//        if((xb+r>=xp2+wp2)&&(xb-r<=xp2+wp2))
//        {
//            if(yb>=yp2 && yb+r<yp2+head)
//             {
//               dyb=-10;
//               dxb=-dxb;
//               stop_ball=1;
//             }
//        }
//        if(dxb==0)
//        {
//
//        if((xb+r>=xp2+wp2)&&(xb-r<=xp2+wp2-3)){
//
//        if(shoot_havaee2 ==0 && shoot_zamini2==0)
//        {
//            if(yb+r>=yp2+head  &&  yb+r<=yp2+hp)
//            {
//                dxb=+3;
//            }
//        }
//
//        }
//        }
//
//        if(dxb<0){
//        if((xb+r>=xp2+wp2)&&(xb-r<=xp2+wp2-10)){
//
//        if(shoot_havaee2 ==0 && shoot_zamini2==0)
//        {
//            if(yb+r>=yp2+head  &&  yb+r<=yp2+hp)
//            {
//                dxb=-dxb;
//
//            }
//        }
//        }
//
//        }


        if(xb+r>xp1+wp1-25 && xb-r<=xp1+wp1)
        {
            if(yb<=yp1+nose/2  && yb+r>=yp1+20)
            {
            dyb=-10;
            dxb=10;
            }
        }
        if(xb+r>=xp1+wp1 &&xb-r<=xp1+wp1)
        {
            if(yb>yp1+nose/2 && yb<=yp1+hp)
            {
                dxb=-dxb;
                if(dxb<=15)
                    dxb=15;
                if(dxb>=25)
                    dxb=25;
                xb=xp1+wp1+r;

            }
            else if(yb>yp1+hp  &&  yb-r<=yp1-hp-5)

            {
                dxb=7;

            }



        }
        if(xb-r<xp2+25 && xb+r>=xp2)
        {
            if(yb<=yp2+nose/2  && yb+r>=yp2+20)
            {
            dyb=-10;
            dxb=-10;
            }
        }
        if(xb-r<=xp2 && xb+r>=xp2)
        {
            if(yb>yp2+nose/2 && yb<=yp2+hp)
            {
                dxb=-dxb;
                xb=xp2-r;
                if(dxb>-15)
                {
                    dxb=-15;
                }
                if(dxb<=-25)
                {
                    dxb=-25;
                }

            }

            else if(yb>yp2+hp  &&  yb-r<=yp2-hp-5)

            {
                dxb=-7;
            }

        }
        if(xb-r<=xp1 &&  xb+r>=xp2+wp2 && yb+r>=yp1 && yb+r>=yp2 &&  yb-r<=yp1+hp && yb-r<=yp2+hp)
        if(xp1<xp2+wp2+2*r+50)
        {
            if(abs(int(dxb))>=15)
            {
                yb-=100;
                dyb=-10;
                stop_ball=1;
            }
        }
             }

        if(vfall)
        {
            Mix_Chunk *ops = Mix_LoadWAV("v fall.wav");
            Mix_PlayChannel(-1,ops,0);
            vfall=0;

        }

             shoot_havaee1=0;
             shoot_havaee2=0;
             shoot_zamini1=0;
             shoot_zamini2=0;
             fall1=0;
             fall2=0;



        SDL_RenderPresent(m_renderer);
        if(v_tir)
        {
            Mix_PlayChannel(-1,tir,0);
            v_tir=0;
        }
        if(shoot)
        {
            Mix_PlayChannel(-1,vshoot,0);
           shoot=0;
        }
        if(v_punch)
        {
            SDL_Delay(70);
            Mix_PlayChannel(-1,sound_punch,0);
           v_punch=0;
        }
        if(collision)
        {
            Mix_PlayChannel(-1,colllision_sound,0);
           collision=0;
        }
            if(punch1 || punch2)
                SDL_Delay(30);
            if((head_fire1 && b1)||(head_fire2 && b2))
                SDL_Delay(20);
            if(goalshod)
            {
                     Mix_PlayChannel(-1,vgoal,0);

                                SDL_Delay(2000);

     xb=W/2;
     yb=H/2 , r=25 , R=255, B=255, G=255;
     theta1=0,theta2=0;
     dyb=10;
     hashie=200;
     wall_right=hashie,wall_left=W-hashie;
     flag1=0,flag2=0,shoot_zamini1=0,shoot_zamini2=0,shoot_havaee1=0,shoot_havaee2=0,tripple_clone1=0,tripple_clone2=0;
     stop_ball=1,fall1=0,fall2=0,kick_fire1=0,kick_fire2=0,b1=0,b2=0;
     wp=150,wp1=150,wp2=150,hp=150,counter1=-1,counter2=-1;
     xp1=xgoal1-wp,yp1=floor-hp,dyp1=-10,dyp2=-10,Rp1=100,Bp1=100,Gp1=100;
     xp2=xgoal2,yp2=yp1,fargh=35,fargh1=fargh,fargh2=fargh;
     x_sargardan,y_sargardan,w_sargardan=50,h_sargardan=50,rRotX=80,rRotY=60;
     head=100,nose=65,counter3=200,counter4=200,xp12,xp13,xp22,xp23;
     tball=0,t=W,d_xb,f=37,l=20,ax=10,ay=5,h_net=300,w_net=wall_right;
     round_ball='1';
     ball=1,punch1=0,punch2=0,head_fire1=0,head_fire2=0,tir1=0,tir2=0;
     ayb=1;
     helpme1=W,helpme2=0;
     timeplus+=2;
        texture(m_renderer,0,0,"st.jpg",W,H);
        texture(m_renderer,W-w_net,floor-h_net+20,"net1.png",w_net,h_net);
        texture(m_renderer,0,floor-h_net+20,"net2.png",w_net,h_net);
        texture(m_renderer,xb-r,yb-r,"ball1.png",2*r,2*r);
        texture(m_renderer,xp1,yp1,p11,wp,hp);
        texture(m_renderer,xp2,yp2,p21,wp,hp);
        SDL_RenderPresent(m_renderer);
          Mix_Chunk *whistle = Mix_LoadWAV("whistle.wav");
            Mix_PlayChannel(-1,whistle,0);

            }
            goalshod=0;
//        SDL_RenderClear(m_renderer);

             b1=0;
             b2=0;
       punch1=0;
       punch2=0;
             }




else if(!pause) {


     //rect(m_renderer,0,0,W,H,255,255,255,1);
    int vahed=W/7;
    texture(m_renderer , vahed,H/2-vahed/2,"exit.png",vahed,vahed);
    texture(m_renderer , 3*vahed,H/2-vahed/2,"replay.png",vahed,vahed);
    texture(m_renderer , 5*vahed,H/2-vahed/2,"play1.png",vahed,vahed);
    texture(m_renderer , 4*W/10,2*H/3,"up1.png",vahed/2,vahed/2);
    texture(m_renderer , 4*W/10,2*H/3+vahed/2,"down1.png",vahed/2,vahed/2);
    if(volume>0){

    //rectangleRGBA(m_renderer,4*W/10-vahed-20,2*H/3,4*W/10-vahed-20+vahed,2*H/3+vahed,0,0,0,255);
    rect(m_renderer,4*W/10-vahed-20,2*H/3,vahed,vahed,0, 132, 255,1);
    rect(m_renderer,4*W/10-vahed-20,2*H/3,vahed,vahed,0, 0, 0,0);
    texture(m_renderer , 4*W/10-vahed-20,2*H/3,"sound2.png",vahed,vahed);
    }
    else
    {
       rect(m_renderer,4*W/10-vahed-20,2*H/3,vahed,vahed,0, 132, 255,1);
       rect(m_renderer,4*W/10-vahed-20,2*H/3,vahed,vahed,0, 0, 0,0);
       texture(m_renderer , 4*W/10-vahed-20,2*H/3,"mute2.png",vahed,vahed);
    }




    SDL_RenderPresent(m_renderer);


         SDL_PollEvent(e);
         if(e->type==SDL_MOUSEBUTTONDOWN)
            {
             if((e->button.button==SDL_BUTTON_LEFT))
            {
                int x0=e->motion.x;
                int y0=e->motion.y;
                if(x0>=5*vahed && x0<=6*vahed && y0<=H/2+vahed/2 && y0>=H/2-vahed/2)
                {
                    pause=1;
                    time_pause2=clock();

//                                    Mix_FreeMusic(vpause);

                }
                if(x0>=vahed && x0<=2*vahed && y0<=H/2+vahed/2 && y0>=H/2-vahed/2)
                {
                    return 0;
                }
                if(x0>=3*vahed && x0<=4*vahed && y0<=H/2+vahed/2 && y0>=H/2-vahed/2)
                {


     g1=0,g2=0,w1=0,w2=0,l1=0,l2=0,d1=0,d2=0;
     xb=W/2,yb=H/2,dyb=10;
     r=25 , R=255, B=255, G=255;
     dxb=0,theta1=0,theta2=0;
     floor=650,wr=50;
     hashie=200;
     time_pause1=0,time_pause2=0;
     tball=0,t=W,d_xb,f=37,l=20,ax=10,ay=5,h_net=300,w_net=wall_right,xgoal=120,xgoal2=xgoal,xgoal1=W-xgoal,ygoal=400,ayb=1;
     flag1=0,flag2=0,shoot_zamini1=0,shoot_zamini2=0,shoot_havaee1=0,shoot_havaee2=0,tripple_clone1=0,tripple_clone2=0;
     stop_ball=1,fall1=0,fall2=0,kick_fire1=0,kick_fire2=0,b1=0,b2=0;
     wp=150,wp1=150,wp2=150,hp=150,counter1=-1,counter2=-1;
     xp1=xgoal1-wp1,yp1=floor-hp,dyp1=-10,dyp2=-10,Rp1=100,Bp1=100,Gp1=100;
     xp2=xgoal2,yp2=yp1,fargh=35,fargh1=fargh,fargh2=fargh;
     w_sargardan=50,h_sargardan=50,rRotX=80,rRotY=60;
     font =2;
     x_time=W/2-120;
     y_time=5;
     head=100,nose=65,counter3=200,counter4=200;
     round_ball='1';
     ball=1,punch1=0,punch2=0,head_fire1=0,head_fire2=0,tir1=0,tir2=0,wall1=0,wall2=0,pause=1,v_tir=0,shoot=0;
     helpme1=W,helpme2=0,xwall2=50,xwall1=W-w_net-50,counter_wall1=0,counter_wall2=0,wall_barkhord1=xwall1+80,wall_barkhord2=xwall2+w_net-80;
    //char player1='M',player2='R';
     p11,p22,p23,h1,h2,p21,f1,f2,p12,p13,stime;
     aa1=1,bb1=1,cc1=1,bb2=1,cc2=1,aa2=1,v_punch=0,collision=0,vfall=0;
    volume=50;

    srand(time(NULL));
     start=clock(),timeplus=0;
     pz1=0,pz2=0,power_start1=0,power_start2=0;
     counterz1=0,counterz2=0,power1=0,power2=0,hpower=50,wpower=100,xpower=(W*8)/9,ypower=30;
    if(timegame>=60)
    {
    ta3=rand()%20+10;
    tb3=rand()%20+10;

    }
    if(timegame>=90 )
    {
    ta2=rand()%30+40;
    tb2=rand()%30+40;
    if(timegame>=120)
    {
        ta1=rand()%25+85;
        tb1=rand()%25+85;
    }
    }
        texture(m_renderer,0,0,"st.jpg",W,H);
        texture(m_renderer,W-w_net,floor-h_net+20,"net1.png",w_net,h_net);
        texture(m_renderer,0,floor-h_net+20,"net2.png",w_net,h_net);
        texture(m_renderer,xb-r,yb-r,"ball1.png",2*r,2*r);
        texture(m_renderer,xp1,yp1,p11,wp,hp);
        texture(m_renderer,xp2,yp2,p21,wp,hp);
        SDL_RenderPresent(m_renderer);
        SDL_Delay(1000);
          Mix_Chunk *whistle = Mix_LoadWAV("whistle.wav");
            Mix_PlayChannel(-1,whistle,0);
//          Mix_Chunk *play = Mix_LoadWAV("play.wav");
//            Mix_PlayChannel(-1,play,0);
//                                Mix_Music *vpause = Mix_LoadMUS("pause.MP3");


                }

                if(x0>=4*W/10-20 && x0<=4*W/10+vahed/2-20 && y0<=2*H/3+vahed/2 && y0>=2*H/3)
                {
                    volume++;
                    if(volume>=30)
                        volume=30;


                }
                if(x0>=4*W/10-20 && x0<=4*W/10+vahed/2-20 && y0<=2*H/3+vahed && y0>=2*H/3+vahed/2)
                {
                    volume--;
                    if(volume<=0)
                    {
                        volume=0;

                    }

                }
                SDL_RenderPresent(m_renderer);

            }


            }


       e->type=0;
    }

    }










    SDL_DestroyWindow( m_window );
    SDL_DestroyRenderer( m_renderer );
	IMG_Quit();
	SDL_Quit();
    return 0;

}


void HomePage(SDL_Renderer *m_renderer,int W,int H)
{
struct pic QuickGame;
struct pic Setting;
struct pic Scoreboard;
struct pic About;

//QuickGame.xp=400;
//QuickGame.yp=500;
//QuickGame.w=500;
//QuickGame.h=200;

QuickGame.xp=W/(3.415);
QuickGame.yp=H/(1.536);
QuickGame.w=W/(2.732);
QuickGame.h=H/(3.84);


//Setting.xp=1000;
//Setting.yp=400;
//Setting.w=350;
//Setting.h=140;

Setting.xp=W/(1.366);
Setting.yp=H/(1.92);
Setting.w=W/(3.9028);
Setting.h=H/(5.4857);

//Scoreboard.xp=1000;
//Scoreboard.yp=540;
//Scoreboard.w=350;
//Scoreboard.h=140;
Scoreboard.xp=W/(1.366);
Scoreboard.yp=H/(1.4222);
Scoreboard.w=W/(3.9028);
Scoreboard.h=H/(5.4857);

//About.xp=10;
//About.yp=660;
//About.w=150;
//About.h=100;

About.xp=W/(136.6);
About.yp=H/(1.163636);
About.w=W/(9.1066);
About.h=H/(7.68);



texture(m_renderer,0,0,"1.jpg",W,H);
texture(m_renderer,QuickGame.xp,QuickGame.yp,"qg.png",QuickGame.w,QuickGame.h);
texture(m_renderer,Setting.xp,Setting.yp,"sett.png",Setting.w,Setting.h);
texture(m_renderer,Scoreboard.xp,Scoreboard.yp,"sb.png",Scoreboard.w,Scoreboard.h);
texture(m_renderer,About.xp,About.yp,"aboutus.png",About.w,About.h);
//texture(m_renderer,Scoreboard.xp-175,Scoreboard.yp-15,"9.png",Scoreboard.w+350,Scoreboard.h+30);
//texture(m_renderer,Setting.xp-175,Setting.yp-15,"9.png",Setting.w+350,Setting.h+30);
//texture(m_renderer,QuickGame.xp-250,QuickGame.yp-22,"9.png",QuickGame.w+500,QuickGame.h+40);
//texture(m_renderer,About.xp-70,About.yp-10,"9.png",About.w+140,About.h+20);

texture(m_renderer,Scoreboard.xp-W/(7.805714),Scoreboard.yp-H/(51.2),"9.png",Scoreboard.w+W/(3.9028),Scoreboard.h+H/(25.6) );
texture(m_renderer,Setting.xp-W/(7.805714),Setting.yp-H/(51.2),"9.png",Setting.w+W/(3.9028),Setting.h+H/(25.6));
texture(m_renderer,QuickGame.xp-W/(5.464),QuickGame.yp-H/(34.9090),"9.png",QuickGame.w+W/(2.732),QuickGame.h+H/(19.2));
texture(m_renderer,About.xp-W/(19.51428),About.yp-H/(76.8),"9.png",About.w+W/(9.757142),About.h+H/(38.4));


SDL_RenderPresent(m_renderer);
bool flag=true;
SDL_Event *e = new SDL_Event();
struct mouse mouse_Homepage;



    while(flag)
    {
            SDL_PollEvent(e);
            if(e->type == SDL_KEYDOWN)
            {
                if(e->key.keysym.sym==SDLK_ESCAPE)
                    {
                    flag=false;
                    ReloadHomepage=0;
                    }

            }
            if(e->type==SDL_MOUSEBUTTONDOWN)
            {
                if(e->button.button == SDL_BUTTON_LEFT)
                {
                  mouse_Homepage.x=e->button.x;
                  mouse_Homepage.y=e->button.y;
                  if( (mouse_Homepage.x>Setting.xp) && (mouse_Homepage.x<Setting.xp+Setting.w) && (mouse_Homepage.y>Setting.yp) &&(mouse_Homepage.y<Setting.yp+Setting.h) )
                  {
                    SettingPage(m_renderer,H,W);
                     flag=false;
                  }

                  if( (mouse_Homepage.x>QuickGame.xp) && (mouse_Homepage.x<QuickGame.xp+QuickGame.w) && (mouse_Homepage.y>QuickGame.yp) &&(mouse_Homepage.y<QuickGame.yp+QuickGame.h) )
                  {
                    NamePage(m_renderer,W,H);
                     flag=false;
                  }

                   if( (mouse_Homepage.x>Scoreboard.xp) && (mouse_Homepage.x<Scoreboard.xp+Scoreboard.w) && (mouse_Homepage.y>Scoreboard.yp) &&(mouse_Homepage.y<Scoreboard.yp+Scoreboard.h) )
                  {
                    ScoreboardPage(m_renderer,W,H);
                     flag=false;
                  }

                  if( (mouse_Homepage.x>About.xp) && (mouse_Homepage.x<About.xp+About.w) && (mouse_Homepage.y>About.yp) &&(mouse_Homepage.y<About.yp+About.h) )
                  {
                    AboutPage(m_renderer,W,H);
                     flag=false;
                  }


                }
            }
        e->type=0;
    }
    //if(choosepage==true && (player1name.length()!=0 && player2name.length()!=0) )
    if(choosepage==true)
    {
        choosepage=0;
        ChoosePage(m_renderer,W,H);
    }
//    if(Reload)
//     {
//        Reload=0;
//        HomePage(m_renderer,1366,768);
//     }
}

void AboutPage(SDL_Renderer *m_renderer,int W,int H)
{

texture(m_renderer,0,0,"about.png",W,H);
SDL_RenderPresent(m_renderer);


SDL_Event *e = new SDL_Event();
    bool flag=true;
    while(flag)
    {
        SDL_PollEvent(e);
        if(e->type == SDL_KEYDOWN)
            {
                if(e->key.keysym.sym==SDLK_ESCAPE)
                    {
                    flag=false;
                    ReloadHomepage=1;
                    }

            }
            e->type=0;

    }



}

void ChoosePage(SDL_Renderer *m_renderer,int W,int H)
{

    struct pic rightbutton1;
    struct pic leftbutton1;
    struct pic rightbutton2;
    struct pic leftbutton2;
    struct pic kickoff;
//    rightbutton1.xp=550;
//    rightbutton1.yp=290-42;
//    rightbutton1.w=60;
//    rightbutton1.h=60;

    rightbutton1.xp=W/(2.48);
    rightbutton1.yp=H/(3.09);
    rightbutton1.w=W/(22.76);
    rightbutton1.h=H/(12.8);

//    leftbutton1.xp=225;
//    leftbutton1.yp=290-42;
//    leftbutton1.w=60;
//    leftbutton1.h=60;

    leftbutton1.xp=W/(6.07);
    leftbutton1.yp=H/(3.09);
    leftbutton1.w=W/(22.76);
    leftbutton1.h=H/(12.8);

//    rightbutton2.xp=1080;
//    rightbutton2.yp=290-42;
//    rightbutton2.w=60;
//    rightbutton2.h=60;

    rightbutton2.xp=W/(1.26);
    rightbutton2.yp=H/(3.09);
    rightbutton2.w=W/(22.76);
    rightbutton2.h=H/(12.8);

//    leftbutton2.xp=750;
//    leftbutton2.yp=290-42;
//    leftbutton2.w=60;
//    leftbutton2.h=60;

    leftbutton2.xp=W/(1.82);
    leftbutton2.yp=H/(3.09);
    leftbutton2.w=W/(22.76);
    leftbutton2.h=H/(12.8);

//    kickoff.xp=590;
//    kickoff.yp=500;
//    kickoff.w=200;
//    kickoff.h=120;

    kickoff.xp=W/(2.31525);
    kickoff.yp=H/(1.53);
    kickoff.w=W/(6.83);
    kickoff.h=H/(6.4);

//    bool player1char=1;  // 1=ronaldo 0=messi
//    bool player2char=0;
    texture(m_renderer,0,0,"choose.png",W,H);
    //window_color(m_renderer,255,255,255);
    string chooser="ronaldo-choose.png";
    string choosem="m-choose.png";
    //texture(m_renderer,220,120,"techframe.png",400,400);
   // texture(m_renderer,220,120-42,"techframer.png",400,400);
    texture(m_renderer,W/(6.2091),H/(9.846),"techframer.png",W/(3.415),H/(1.92));

    //texture(m_renderer,750,120,"techframe.png",400,400);
    //texture(m_renderer,750,120-42,"techframe.png",400,400);
    texture(m_renderer,W/(1.821),H/(9.846),"techframe.png",W/(3.415),H/(1.92));

    //texture(m_renderer,200,220-42,chooser,400,200);
    texture(m_renderer,W/(6.83),H/(4.314),chooser,W/(3.415),H/(3.84));

    //texture(m_renderer,800,200-42,choosem,290,220);
    texture(m_renderer,W/(1.7075),H/(4.86),choosem,W/(4.7103),H/(3.49));

    texture(m_renderer,rightbutton1.xp,rightbutton1.yp,"right.png",rightbutton1.w,rightbutton1.h);
    texture(m_renderer,leftbutton1.xp,leftbutton1.yp,"left.png",leftbutton1.w,leftbutton1.h);
    texture(m_renderer,rightbutton2.xp,rightbutton2.yp,"right.png",rightbutton2.w,rightbutton2.h);
    texture(m_renderer,leftbutton2.xp,leftbutton2.yp,"left.png",leftbutton2.w,leftbutton2.h);
    texture(m_renderer,kickoff.xp,kickoff.yp,"kickoff.png",kickoff.w,kickoff.h);
    //texture(m_renderer,570,220-42,"vs.png",180,200);
    texture(m_renderer,W/(2.3964),H/(4.3146),"vs.png",W/(7.588),H/(3.84) );
    //texture(m_renderer,400,500,"kick fire ball.png",150,100);
    struct pic hfb1;
    struct pic hfb2;
    struct pic tc1;
    struct pic tc2;
    struct pic kfb1;
    struct pic kfb2;
    struct pic ib1;
    struct pic ib2;
    struct pic sw1;
    struct pic sw2;
    struct pic p1;
    struct pic p2;
    //hfb2.xp=220; hfb2.yp=450-48; hfb2.w=150; hfb2.h=100;
    hfb2.xp=W/(6.2091); hfb2.yp=H/(1.9104); hfb2.w=W/(9.106); hfb2.h=H/(7.68);

    hfb1.xp=W-hfb2.xp-hfb2.w; hfb1.yp=hfb2.yp; hfb1.w=hfb2.w; hfb1.h=hfb2.h;

    //tc2.xp=380; tc2.yp=450-48; tc2.w=150; tc2.h=100;
    tc2.xp=W/(3.5947); tc2.yp=H/(1.9104); tc2.w=W/(9.106); tc2.h=H/(7.68);

    tc1.xp=W-tc2.xp-tc2.w; tc1.yp=tc2.yp; tc1.w=tc2.w; tc1.h=tc2.h;

    //kfb2.xp=220; kfb2.yp=520-48; kfb2.w=150; kfb2.h=100;
    kfb2.xp=W/(6.2091); kfb2.yp=H/(1.6271); kfb2.w=W/(9.106); kfb2.h=H/(7.68);

    kfb1.xp=W-kfb2.xp-kfb2.w; kfb1.yp=kfb2.yp; kfb1.w=kfb2.w; kfb1.h=kfb2.h;

    //ib2.xp=380; ib2.yp=520-48; ib2.w=150; ib2.h=100;
    ib2.xp=W/(3.5947); ib2.yp=H/(1.6271); ib2.w=W/(9.106); ib2.h=H/(7.68);

    ib1.xp=W-ib2.xp-ib2.w; ib1.yp=ib2.yp; ib1.w=ib2.w; ib1.h=ib2.h;


    //p2.xp=220; p2.yp=590-48; p2.w=150; p2.h=100;
    p2.xp=W/(6.2091); p2.yp=H/(1.4169); p2.w=W/(9.106); p2.h=H/(7.68);

    p1.xp=W-p2.xp-p2.w; p1.yp=p2.yp; p1.w=p2.w; p1.h=p2.h;

    //sw2.xp=380; sw2.yp=590-48; sw2.w=150; sw2.h=100;
    sw2.xp=W/(3.5947); sw2.yp=H/(1.4169); sw2.w=W/(9.106); sw2.h=H/(7.68);
    sw1.xp=W-sw2.xp-sw2.w; sw1.yp=sw2.yp; sw1.w=sw2.w; sw1.h=sw2.h;

    texture(m_renderer,hfb2.xp,hfb2.yp,"head fire ball.png",hfb2.w,hfb2.h);
    texture(m_renderer,tc2.xp,tc2.yp,"triple clone2.png",tc2.w,tc2.h);
    texture(m_renderer,kfb2.xp,kfb2.yp,"kick fire ball.png",kfb2.w,kfb2.h);
    texture(m_renderer,ib2.xp,ib2.yp,"invisible ball.png",ib2.w,ib2.h);
    texture(m_renderer,p2.xp,p2.yp,"punch2.png",p2.w,p2.h);
    texture(m_renderer,sw2.xp,sw2.yp,"strong wall.png",sw2.w,sw2.h);

    texture(m_renderer,hfb1.xp,hfb1.yp,"head fire ball.png",hfb1.w,hfb1.h);
    texture(m_renderer,tc1.xp,tc1.yp,"triple clone2.png",tc1.w,tc1.h);
    texture(m_renderer,kfb1.xp,kfb1.yp,"kick fire ball.png",kfb1.w,kfb1.h);
    texture(m_renderer,ib1.xp,ib1.yp,"invisible ball.png",ib1.w,ib1.h);
    texture(m_renderer,p1.xp,p1.yp,"punch2.png",p1.w,p1.h);
    texture(m_renderer,sw1.xp,sw1.yp,"strong wall.png",sw1.w,sw1.h);
    SDL_RenderPresent(m_renderer);

   // SDL_Delay(5000);
    bool power1b=false,power2b=false,power1a=false,power2a=false;
    bool flag=true;
    SDL_Event *e = new SDL_Event();
    struct mouse mouse_ChoosePage;
   while(flag)
   {
    SDL_PollEvent(e);

    if(e->type == SDL_KEYDOWN)
    {
        if(e->key.keysym.sym==SDLK_ESCAPE)
                    {
                    flag=false;
                    ReloadHomepage=1;
                    }

    }

   if(e->type==SDL_MOUSEBUTTONDOWN)
   {
       if(e->button.button == SDL_BUTTON_LEFT)
       {
           mouse_ChoosePage.x=e->button.x;
           mouse_ChoosePage.y=e->button.y;
           if( (mouse_ChoosePage.x>rightbutton1.xp) && (mouse_ChoosePage.x<rightbutton1.xp+rightbutton1.w) && (mouse_ChoosePage.y>rightbutton1.yp) &&(mouse_ChoosePage.y<rightbutton1.yp+rightbutton1.h) )
           {
            if(player1char==1)
            {
                player1char=0;
//                texture(m_renderer,220,120-42,"techframer.png",400,400);
//                texture(m_renderer,270,200-42,choosem,290,220);
                texture(m_renderer,W/(6.2091),H/(9.8461),"techframer.png",W/(3.415),H/(1.92));
                texture(m_renderer,W/(5.059),H/(4.8607),choosem,W/(4.7103),H/(3.4909));
                SDL_RenderPresent(m_renderer);
            }
            else
            {
                player1char=1;
//                texture(m_renderer,220,120-42,"techframer.png",400,400);
//                texture(m_renderer,200,220-42,chooser,400,200);
                texture(m_renderer,W/(6.2091),H/(9.8461),"techframer.png",W/(3.415),H/(1.92));
                texture(m_renderer,W/(6.83),H/(4.314),chooser,W/(3.415),H/(3.84));
                SDL_RenderPresent(m_renderer);
            }

           }
           else if( (mouse_ChoosePage.x>leftbutton1.xp) && (mouse_ChoosePage.x<leftbutton1.xp+leftbutton1.w) && (mouse_ChoosePage.y>leftbutton1.yp) &&(mouse_ChoosePage.y<leftbutton1.yp+leftbutton1.h) )
           {
            if(player1char==1)
            {
                player1char=0;
//                texture(m_renderer,220,120-42,"techframer.png",400,400);
//                texture(m_renderer,270,200-42,choosem,290,220);
                texture(m_renderer,W/(6.2091),H/(9.8461),"techframer.png",W/(3.415),H/(1.92));
                texture(m_renderer,W/(5.059),H/(4.8607),choosem,W/(4.7103),H/(3.4909));
                SDL_RenderPresent(m_renderer);
            }
            else
            {
                player1char=1;
//                texture(m_renderer,220,120-42,"techframer.png",400,400);
//                texture(m_renderer,200,220-42,chooser,400,200);
                texture(m_renderer,W/(6.2091),H/(9.8461),"techframer.png",W/(3.415),H/(1.92));
                 texture(m_renderer,W/(6.83),H/(4.314),chooser,W/(3.415),H/(3.84));

                SDL_RenderPresent(m_renderer);
            }

           }
           else if( (mouse_ChoosePage.x>rightbutton2.xp) && (mouse_ChoosePage.x<rightbutton2.xp+rightbutton2.w) && (mouse_ChoosePage.y>rightbutton2.yp) &&(mouse_ChoosePage.y<rightbutton2.yp+rightbutton2.h) )
           {
            if(player2char==0)
            {
                player2char=1;
//                texture(m_renderer,750,120-42,"techframe.png",400,400);
//                texture(m_renderer,730,220-42,chooser,400,200);
                texture(m_renderer,W/(1.8213),H/(9.8461),"techframe.png",W/(3.415),H/(1.92));
                texture(m_renderer,W/(1.8712),H/(4.314),chooser,W/(3.415),H/(3.84));

                SDL_RenderPresent(m_renderer);
            }
            else
            {
                player2char=0;
//                texture(m_renderer,750,120-42,"techframe.png",400,400);
//                texture(m_renderer,800,200-42,choosem,290,220);
                texture(m_renderer,W/(1.8213),H/(9.8461),"techframe.png",W/(3.415),H/(1.92));
                texture(m_renderer,W/(1.7075),H/(4.8607),choosem,W/(4.7103),H/(3.4909));
                SDL_RenderPresent(m_renderer);
            }


           }
           else if( (mouse_ChoosePage.x>leftbutton2.xp) && (mouse_ChoosePage.x<leftbutton2.xp+leftbutton2.w) && (mouse_ChoosePage.y>leftbutton2.yp) &&(mouse_ChoosePage.y<leftbutton2.yp+leftbutton2.h) )
           {
            if(player2char==0)
            {
                player2char=1;
//                texture(m_renderer,750,120-42,"techframe.png",400,400);
//                texture(m_renderer,730,220-42,chooser,400,200);
                texture(m_renderer,W/(1.8213),H/(9.8461),"techframe.png",W/(3.415),H/(1.92));
                texture(m_renderer,W/(1.8712),H/(4.314),chooser,W/(3.415),H/(3.84));

                SDL_RenderPresent(m_renderer);
            }
            else
            {
                player2char=0;
//                texture(m_renderer,750,120-42,"techframe.png",400,400);
//                texture(m_renderer,800,200-42,choosem,290,220);
                texture(m_renderer,W/(1.8213),H/(9.8461),"techframe.png",W/(3.415),H/(1.92));
                texture(m_renderer,W/(1.7075),H/(4.8607),choosem,W/(4.7103),H/(3.4909));

                SDL_RenderPresent(m_renderer);
            }
           }
            else if ( (mouse_ChoosePage.x>hfb2.xp) && (mouse_ChoosePage.x<hfb2.xp+hfb2.w) && (mouse_ChoosePage.y>hfb2.yp+H/(34.909091)) &&(mouse_ChoosePage.y<hfb2.yp+hfb2.h-H/(34.909091)) )
            {
                if(power1b==false)
                {
                    hfb=true;
                    power1b=true;
                    texture(m_renderer,W/(3.794),H/(1.1636),"head fire ball.png",W/(9.106),H/(7.68));
                    SDL_RenderPresent(m_renderer);
                }
                else if(power1b==true && power2b==false && hfb==false)
                {
                    hfb=true;
                    power2b=true;
                    texture(m_renderer,W/(2.678),H/(1.1636),"head fire ball.png",W/(9.106),H/(7.68));
                    SDL_RenderPresent(m_renderer);
                }
            }
            else if ( (mouse_ChoosePage.x>hfb1.xp) && (mouse_ChoosePage.x<hfb1.xp+hfb1.w) && (mouse_ChoosePage.y>hfb1.yp+22) &&(mouse_ChoosePage.y<hfb1.yp+hfb1.h-22) )
            {
                if(power1a==false)
                {
                    hfa=true;
                    power1a=true;
                    texture(m_renderer,W-W/(3.794)-hfb1.w,H/(1.1636),"head fire ball.png",W/(9.106),H/(7.68));
                    SDL_RenderPresent(m_renderer);
                }
                else if(power1a==true && power2a==false && hfa==false)
                {
                    hfa=true;
                    power2a=true;
                    texture(m_renderer,W-W/(2.678)-hfb1.w,H/(1.1636),"head fire ball.png",W/(9.106),H/(7.68));
                    SDL_RenderPresent(m_renderer);
                }

            }
            else if ( (mouse_ChoosePage.x>kfb2.xp) && (mouse_ChoosePage.x<kfb2.xp+kfb2.w) && (mouse_ChoosePage.y>kfb2.yp+22) &&(mouse_ChoosePage.y<kfb2.yp+kfb2.h-22) )
            {
                if(power1b==false)
                {
                    kfb=true;
                    power1b=true;
                    texture(m_renderer,W/(3.794),H/(1.1636),"kick fire ball.png",W/(9.106),H/(7.68));
                    SDL_RenderPresent(m_renderer);
                }
                else if(power1b==true && power2b==false && kfb==false)
                {
                    kfb=true;
                    power2b=true;
                    texture(m_renderer,W/(2.678),H/(1.1636),"kick fire ball.png",W/(9.106),H/(7.68));
                    SDL_RenderPresent(m_renderer);
                }

            }
            else if ( (mouse_ChoosePage.x>kfb1.xp) && (mouse_ChoosePage.x<kfb1.xp+kfb1.w) && (mouse_ChoosePage.y>kfb1.yp+22) &&(mouse_ChoosePage.y<kfb1.yp+kfb1.h-22) )
            {
                if(power1a==false)
                {
                    kfa=true;
                    power1a=true;
                    texture(m_renderer,W-W/(3.794)-kfb1.w,H/(1.1636),"kick fire ball.png",W/(9.106),H/(7.68));
                    SDL_RenderPresent(m_renderer);
                }
                else if(power1a==true && power2a==false && kfa==false)
                {
                    kfa=true;
                    power2a=true;
                    texture(m_renderer,W-W/(2.678)-kfb1.w,H/(1.1636),"kick fire ball.png",W/(9.106),H/(7.68));
                    SDL_RenderPresent(m_renderer);
                }

            }

            else if ( (mouse_ChoosePage.x>tc2.xp) && (mouse_ChoosePage.x<tc2.xp+tc2.w) && (mouse_ChoosePage.y>tc2.yp+22) &&(mouse_ChoosePage.y<tc2.yp+tc2.h-22) )
            {
               if(power1b==false)
                {
                    tcb=true;
                    power1b=true;
                    texture(m_renderer,W/(3.794),H/(1.1636),"triple clone2.png",W/(9.106),H/(7.68));
                    SDL_RenderPresent(m_renderer);
                }
                else if(power1b==true && power2b==false && tcb==false)
                {
                    tcb=true;
                    power2b=true;
                    texture(m_renderer,W/(2.678),H/(1.1636),"triple clone2.png",W/(9.106),H/(7.68));
                    SDL_RenderPresent(m_renderer);
                }

            }
            else if ( (mouse_ChoosePage.x>tc1.xp) && (mouse_ChoosePage.x<tc1.xp+tc1.w) && (mouse_ChoosePage.y>tc1.yp+22) &&(mouse_ChoosePage.y<tc1.yp+tc1.h-22) )
            {
                if(power1a==false)
                {
                    tca=true;
                    power1a=true;
                    texture(m_renderer,W-W/(3.794)-tc1.w,H/(1.1636),"triple clone2.png",W/(9.106),H/(7.68));
                    SDL_RenderPresent(m_renderer);
                }
                else if(power1a==true && power2a==false && tca==false)
                {
                    tca=true;
                    power2a=true;
                    texture(m_renderer,W-W/(2.678)-tc1.w,H/(1.1636),"triple clone2.png",W/(9.106),H/(7.68));
                    SDL_RenderPresent(m_renderer);
                }
            }

            else if ( (mouse_ChoosePage.x>ib2.xp) && (mouse_ChoosePage.x<ib2.xp+ib2.w) && (mouse_ChoosePage.y>ib2.yp+22) &&(mouse_ChoosePage.y<ib2.yp+ib2.h-22) )
            {
                if(power1b==false)
                {
                    ibb=true;
                    power1b=true;
                    texture(m_renderer,W/(3.794),H/(1.1636),"invisible ball.png",W/(9.106),H/(7.68));
                    SDL_RenderPresent(m_renderer);
                }
                else if(power1b==true && power2b==false && ibb==false)
                {
                    ibb=true;
                    power2b=true;
                    texture(m_renderer,W/(2.678),H/(1.1636),"invisible ball.png",W/(9.106),H/(7.68));
                    SDL_RenderPresent(m_renderer);
                }
            }
            else if ( (mouse_ChoosePage.x>ib1.xp) && (mouse_ChoosePage.x<ib1.xp+ib1.w) && (mouse_ChoosePage.y>ib1.yp+22) &&(mouse_ChoosePage.y<ib1.yp+ib1.h-22) )
            {
                if(power1a==false)
                {
                    iba=true;
                    power1a=true;
                    texture(m_renderer,W-W/(3.794)-ib1.w,H/(1.1636),"invisible ball.png",W/(9.106),H/(7.68));
                    SDL_RenderPresent(m_renderer);
                }
                else if(power1a==true && power2a==false && iba==false)
                {
                    iba=true;
                    power2a=true;
                    texture(m_renderer,W-W/(2.678)-ib1.w,H/(1.1636),"invisible ball.png",W/(9.106),H/(7.68));
                    SDL_RenderPresent(m_renderer);
                }
            }
            else if ( (mouse_ChoosePage.x>sw2.xp) && (mouse_ChoosePage.x<sw2.xp+sw2.w) && (mouse_ChoosePage.y>sw2.yp+22) &&(mouse_ChoosePage.y<sw2.yp+sw2.h-22) )
            {
                if(power1b==false)
                {
                    swb=true;
                    power1b=true;
                    texture(m_renderer,W/(3.794),H/(1.1636),"strong wall.png",W/(9.106),H/(7.68));
                    SDL_RenderPresent(m_renderer);
                }
                else if(power1b==true && power2b==false && swb==false)
                {
                    swb=true;
                    power2b=true;
                    texture(m_renderer,W/(2.678),H/(1.1636),"strong wall.png",W/(9.106),H/(7.68));
                    SDL_RenderPresent(m_renderer);
                }
            }
            else if ( (mouse_ChoosePage.x>sw1.xp) && (mouse_ChoosePage.x<sw1.xp+sw1.w) && (mouse_ChoosePage.y>sw1.yp+22) &&(mouse_ChoosePage.y<sw1.yp+sw1.h-22) )
            {
                if(power1a==false)
                {
                    swa=true;
                    power1a=true;
                    texture(m_renderer,W-W/(3.794)-sw1.w,H/(1.1636),"strong wall.png",W/(9.106),H/(7.68));
                    SDL_RenderPresent(m_renderer);
                }
                else if(power1a==true && power2a==false && swa==false)
                {
                    swa=true;
                    power2a=true;
                    texture(m_renderer,W-W/(2.678)-sw1.w,H/(1.1636),"strong wall.png",W/(9.106),H/(7.68));
                    SDL_RenderPresent(m_renderer);
                }
            }
            else if ( (mouse_ChoosePage.x>p2.xp) && (mouse_ChoosePage.x<p2.xp+p2.w) && (mouse_ChoosePage.y>p2.yp+22) &&(mouse_ChoosePage.y<p2.yp+p2.h-22) )
            {
                if(power1b==false)
                {
                    pub=true;
                    power1b=true;
                    texture(m_renderer,W/(3.794),H/(1.1636),"punch2.png",W/(9.106),H/(7.68));
                    SDL_RenderPresent(m_renderer);
                }
                else if(power1b==true && power2b==false && pub==false)
                {
                    pub=true;
                    power2b=true;
                    texture(m_renderer,W/(2.678),H/(1.1636),"punch2.png",W/(9.106),H/(7.68));
                    SDL_RenderPresent(m_renderer);
                }
            }
            else if ( (mouse_ChoosePage.x>p1.xp) && (mouse_ChoosePage.x<p1.xp+p1.w) && (mouse_ChoosePage.y>p1.yp+22) &&(mouse_ChoosePage.y<p1.yp+p1.h-22) )
            {
                if(power1a==false)
                {
                    pua=true;
                    power1a=true;
                    texture(m_renderer,W-W/(3.794)-p1.w,H/(1.1636),"punch2.png",W/(9.106),H/(7.68));
                    SDL_RenderPresent(m_renderer);
                }
                else if(power1a==true && power2a==false && pua==false)
                {
                    pua=true;
                    power2a=true;
                    texture(m_renderer,W-W/(2.678)-p1.w,H/(1.1636),"punch2.png",W/(9.106),H/(7.68));
                    //texture(m_renderer,W-510-p1.w,660,"punch2.png",W/(9.106),H/(7.68));
                    SDL_RenderPresent(m_renderer);
                }
            }
            else if ( (mouse_ChoosePage.x>kickoff.xp) && (mouse_ChoosePage.x<kickoff.xp+kickoff.w) && (mouse_ChoosePage.y>kickoff.yp) &&(mouse_ChoosePage.y<kickoff.yp+kickoff.h) )
            {
                flag=0;
                startgame=1;
            }
       }
   }
    e->type=0;
   }

//            if(player1char==1) cout<<"p1=ronaldo"<<endl;
//            else cout<<"p1=messi"<<endl;
//            if(player2char==1) cout<<"p2=ronaldo";
//            else cout<<"p2=messi";
}

void ScoreboardPage(SDL_Renderer *m_renderer,int W,int H)
{
            string playernamedata[20]="";
            short int games[20],wins[20],draw[20],lose[20],gf[20],ga[20],gp[20],pts[20];
            int i=0;
            ifstream in;
            in.open("data.txt");
            if( in.good() )
            {

                while( 1 )
                {

                    in>>playernamedata[i];
                    if(playernamedata[i]!="end") in>>games[i]>>wins[i]>>draw[i]>>lose[i]>>gf[i]>>ga[i]>>gp[i]>>pts[i];
                    else break;
                    i++;
                }

             in.close();
            }

    short int order[25];
    short int checked[5]={-1,-1,-1,-1,-1};
    //int max1=0;
    for(int k=0;k<5;k++)
    {
    int max1=-1;
    int max2=-1;
    for(int j=0;j<i;j++)
    {
        if( j!=checked[0] && j!=checked[1] && j!=checked[2] && j!=checked[3] && j!=checked[4] )
        {

            if(pts[j]>max1)
            {
                max1=pts[j];
                max2=j;
            }

        }
    }
    checked[k]=max2;
    }

    for(int q=0;q<4;q++)
    {
        if( pts[checked[q+1]]==pts[checked[q]] ) if(gp[checked[q+1]] > gp[checked[q]]) swap(checked[q],checked[q+1]);
    }

    string sgames[5],swins[5],sdraw[5],slose[5],sgf[5],sga[5],sgp[5],spts[5];

    for(int r=0;r<5;r++)
    {
        sgames[r]=to_string(games[checked[r]]);
        swins[r]=to_string(wins[checked[r]]);
        sdraw[r]=to_string(draw[checked[r]]);
        slose[r]=to_string(lose[checked[r]]);
        sgf[r]=to_string(gf[checked[r]]);
        sga[r]=to_string(ga[checked[r]]);
        sgp[r]=to_string(gp[checked[r]]);
        spts[r]=to_string(pts[checked[r]]);


    }

//    for(int y=0;y<5;y++)
//        cout<<spts[y]<<endl;


//    for(int y=0;y<5;y++)
//        cout<<checked[y];

    const char *text;
    int font =2;
    int x_position=100;
    int y_position=100;
    int R=0;
    int G=0;
    int B=0;
    int A=250;


    window_color(m_renderer,250,250,250);
    //texture(m_renderer,0,0,"leader5.png",W,H);
    texture(m_renderer,0,0,"leader11.png",W,H);

    //text1(m_renderer,200,390,text,2,0,0,0,255,48);
    for(int row=0;row<5;row++)
    {
        x_position=100;
        y_position=110+row*90;
        text=playernamedata[checked[row]].c_str();
        text1(m_renderer,x_position,y_position,text,font,R,G,B,A,48);
    }

    for(int row=0;row<5;row++)
    {
        x_position=550;
        y_position=110+row*90;
        text=sgames[row].c_str();
        text1(m_renderer,x_position,y_position,text,font,R,G,B,A,40);
    }

    for(int row=0;row<5;row++)
    {
        x_position=640;
        y_position=110+row*90;
        text=swins[row].c_str();
        text1(m_renderer,x_position,y_position,text,font,R,G,B,A,40);
    }

    for(int row=0;row<5;row++)
    {
        x_position=730;
        y_position=110+row*90;
        text=sdraw[row].c_str();
        text1(m_renderer,x_position,y_position,text,font,R,G,B,A,40);
    }
    for(int row=0;row<5;row++)
    {
        x_position=810;
        y_position=110+row*90;
        text=slose[row].c_str();
        text1(m_renderer,x_position,y_position,text,font,R,G,B,A,40);
    }

    for(int row=0;row<5;row++)
    {
        x_position=890;
        y_position=110+row*90;
        text=sgf[row].c_str();
        text1(m_renderer,x_position,y_position,text,font,R,G,B,A,40);
    }

    for(int row=0;row<5;row++)
    {
        x_position=990;
        y_position=110+row*90;
        text=sga[row].c_str();
        text1(m_renderer,x_position,y_position,text,font,R,G,B,A,40);
    }

    for(int row=0;row<5;row++)
    {
        x_position=1080;
        y_position=110+row*90;
        text=sgp[row].c_str();
        text1(m_renderer,x_position,y_position,text,font,R,G,B,A,40);
    }

    for(int row=0;row<5;row++)
    {
        x_position=1170;
        y_position=110+row*90;
        text=spts[row].c_str();
        text1(m_renderer,x_position,y_position,text,font,R,G,B,A,40);
    }

    SDL_RenderPresent(m_renderer);
    //SDL_Delay(3000);
    //window_color(m_renderer,0,255,0);

    SDL_Event *e = new SDL_Event();
    bool flag=true;
    while(flag)
    {
        SDL_PollEvent(e);
        if(e->type == SDL_KEYDOWN)
            {
                if(e->key.keysym.sym==SDLK_ESCAPE)
                    {
                    flag=false;
                    ReloadHomepage=1;
                    }

            }
            e->type=0;

    }


    //ReloadHomepage=1;
    //HomePage(m_renderer,1366,768);
}


void NamePage(SDL_Renderer *m_renderer,int W,int H)
{
struct pic inputbox2;
struct pic inputbox1;
struct pic nextbox;
//inputbox1.xp=500;
//inputbox1.yp=275;
//inputbox1.w=500;
//inputbox1.h=50;
inputbox1.xp=W/(2.732);
inputbox1.yp=H/(2.7928);
inputbox1.w=W/(2.732);
inputbox1.h=H/(15.36);


//inputbox2.xp=500;
//inputbox2.yp=325;
//inputbox2.w=500;
//inputbox2.h=50;
inputbox2.xp=W/(2.732);
inputbox2.yp=H/(2.3631);
inputbox2.w=W/(2.732);
inputbox2.h=H/(15.36);



nextbox.xp=915;
nextbox.yp=480;
nextbox.w=200;
nextbox.h=150;

rect(m_renderer,220,210,880,370,100,200,100,1);
const char * text ="Player 1 :";
int font =2;
int x_position=320;
int y_position=170;
int R=0;
int G=0;
int B=0;
int A=250;
text1(m_renderer,x_position,y_position,text,font,R,G,B,A,45);
//string s="player";
//text=s.c_str();
text ="Player 2 :";
x_position=320;
y_position=220;
text1(m_renderer,x_position,y_position,text,font,R,G,B,A,45);
texture(m_renderer,200,190,"name11.png",900,400);
texture(m_renderer,180,175,"name2.png",960,455);
texture(m_renderer,inputbox1.xp,inputbox1.yp,"9.png",inputbox1.w,inputbox1.h);
texture(m_renderer,inputbox2.xp,inputbox2.yp,"9.png",inputbox2.w,inputbox2.h);
texture(m_renderer,nextbox.xp,nextbox.yp,"next.png",nextbox.w,nextbox.h);
SDL_RenderPresent(m_renderer);
struct mouse mouse_NamePage;
SDL_Event *e = new SDL_Event();
bool flag=true;
while(flag )
    {
        SDL_PollEvent(e);
        if(backhome)
        {
            flag=0;
            backhome=0;
        }
            if(e->type == SDL_KEYDOWN)
            {
                if(e->key.keysym.sym==SDLK_ESCAPE)
                    {
                        flag=false;
                        //HomePage(m_renderer,1366,768);
                        ReloadHomepage=1;
                    }
            }
            if(e->type==SDL_MOUSEBUTTONDOWN)
            {
                    if(e->button.button == SDL_BUTTON_LEFT)
                    {
                        mouse_NamePage.x=e->button.x;
                        mouse_NamePage.y=e->button.y;
                        if( (mouse_NamePage.x>inputbox1.xp) && (mouse_NamePage.x<(inputbox1.xp+inputbox1.w) ) && (mouse_NamePage.y>inputbox1.yp) &&  (mouse_NamePage.y<(inputbox1.yp+inputbox1.h) )  )
                        {
                            getkey1(m_renderer,inputbox1);
                            //if(ReloadHomepage) flag=0;
                            if(K1toK2)
                            {
                                K1toK2=0;
                                getkey2(m_renderer,inputbox2);

                            }
                        }
                        else if( (mouse_NamePage.x>inputbox2.xp) && (mouse_NamePage.x<(inputbox2.xp+inputbox2.w) ) && (mouse_NamePage.y>inputbox2.yp) &&  (mouse_NamePage.y<(inputbox2.yp+inputbox2.h) )  )
                        {
                            getkey2(m_renderer,inputbox2);
                        }
                        else if((mouse_NamePage.x>nextbox.xp) && (mouse_NamePage.x<(nextbox.xp+nextbox.w) ) && (mouse_NamePage.y>nextbox.yp) &&  (mouse_NamePage.y<(nextbox.yp+nextbox.h) ))
                        {
                            choosepage=true;
                            flag=false;
                        }
                        else
                        {
                            flag=0;
                            ReloadHomepage=1;
                        }
                    }
            }
        e->type=0;
    }

    if(choosepage)
{
string name,name1="",name2="";
int game1,game2,win1,win2,draw1,draw2,lose1,lose2,golzade1,golzade2,golkhorde1,golkhorde2,tafazol1,tafazol2,point1,point2;
int a;
ifstream in;
in.open("data.txt");
if(in.good())
{
    flag=true;

    while(flag)
    {

        in>>name;
        if(name=="end") flag=0;
        else{
         if(name==player1name)
         {
             name1=name;
             in>>game1>>win1>>draw1>>lose1>>golzade1>>golkhorde1>>tafazol1>>point1;
             //cout<<"are";
             //flag=0;
         }
         else if(name==player2name)
         {
             name2=name;
             in>>game2>>win2>>draw2>>lose2>>golzade2>>golkhorde2>>tafazol2>>point2;
             //cout<<"are";
             //flag=0;
         }
         else
            for(int i=0;i<8;i++) in>>a;
        }
    }
}
in.close();
string n1,n2;
if(name1!="")
{
    //cout<<name1<<" "<<game1<<" "<<win1<<" "<<draw1<<" "<<lose1<<" "<<golzade1<<" "<<golkhorde1<<" "<<tafazol1<<" "<<point1;
    //n1=name1+" "+to_string(game1)+" "+to_string(win1)+" "+to_string(draw1)+" "+to_string(lose1)+" "+to_string(golzade1)+" "+to_string(golkhorde1)+" "+to_string(tafazol1)+" "+to_string(point1);
    n1="P:"+to_string(game1)+" W:"+to_string(win1)+" D:"+to_string(draw1)+" L:"+to_string(lose1)+" GF:"+to_string(golzade1)+" GA:"+to_string(golkhorde1)+" +/-:"+to_string(tafazol1)+" PTS:"+to_string(point1);
    //cout<<n1;
    text =(name1+":").c_str();
    x_position=320;
    y_position=260;
    text1(m_renderer,x_position,y_position,text,font,R,G,B,A,40);
    text=n1.c_str();
    x_position=320;
    y_position=310;
    text1(m_renderer,x_position,y_position,text,font,R,G,B,A,25);
}
else if(name1=="")
{
    text=("'"+player1name+"'" + " is a new player!").c_str();
    x_position=320;
    y_position=280;
    text1(m_renderer,x_position,y_position,text,font,R,G,B,A,40);

}
if(name2!="")
{
    //cout<<name2<<" "<<game2<<" "<<win2<<" "<<draw2<<" "<<lose2<<" "<<golzade2<<" "<<golkhorde2<<" "<<tafazol2<<" "<<point2;
    //n2=name2+" "+to_string(game2)+" "+to_string(win2)+" "+to_string(draw2)+" "+to_string(lose2)+" "+to_string(golzade2)+" "+to_string(golkhorde2)+" "+to_string(tafazol2)+" "+to_string(point2);
    //cout<<n2;
    n2="P:"+to_string(game2)+" W:"+to_string(win2)+" D:"+to_string(draw2)+" L:"+to_string(lose2)+" GF:"+to_string(golzade2)+" GA:"+to_string(golkhorde2)+" +/-:"+to_string(tafazol2)+" PTS:"+to_string(point2);
    text =(name2+":").c_str();
    x_position=320;
    y_position=330;
    text1(m_renderer,x_position,y_position,text,font,R,G,B,A,40);
    text=n2.c_str();
    x_position=320;
    y_position=380;
    text1(m_renderer,x_position,y_position,text,font,R,G,B,A,25);
}
else if(name2==""){
    text=("'"+player2name+"'" + " is a new player!").c_str();
    x_position=320;
    y_position=380;
    text1(m_renderer,x_position,y_position,text,font,R,G,B,A,40);

}
SDL_Delay(4000);
}



}

void SettingPage(SDL_Renderer *m_renderer,int H,int W)
{
        SDL_Event *e = new SDL_Event();

    //window_color(m_renderer,0,255,0);
//    rect(m_renderer,100,120,1150,600,100,200,100,1);
//    texture(m_renderer,40,65,"57.png",1265,705);
//
    rect(m_renderer,W/(13.66) ,H/(6.4),W/(1.1878),H/(1.28),100,200,100,1);
    texture(m_renderer,W/(34.15),H/(11.8153),"57.png",W/(1.0798),H/(1.0893));
    bool ent1=0,ent2=0,ent3=0,ent4=0,ent5=0,ent6=0,ent7=0,ent8=0,ent9=0,ent10=0,ent11=0,ent12=0,ent13=0,ent14=0,ent15=0;
    bool sel[10],cel[3];
    for(int i=0;i<10;i++)
    {
        sel[i]=0;
    }
    for(int i=0;i<3;i++)
    {
        cel[i]=0;
    }
    bool flag=true;
    while(flag)
    {

        SDL_PollEvent(e);
        if(e->type == SDL_KEYDOWN)
            {

                if(e->key.keysym.sym==SDLK_ESCAPE)
                    {
                    flag=false;
                    ReloadHomepage=1;
                    }

            }

    texture(m_renderer , W/10,H/7-150,"goal limit1.png",900,400);
    texture(m_renderer , W/10,3*H/7-160,"time limit1.png",900,400);
    ellipse(m_renderer,W/10+1000,H/7+50,20,20,0,0,255,ent1);

    ellipse(m_renderer,W/10+1000,3*H/7+50,20,20,0,0,255,ent2);

    int vahed=W/7;

    texture(m_renderer , 8*W/10,2*H/3,"up.png",vahed/2,vahed/2);
    texture(m_renderer , 8*W/10,2*H/3+vahed/2,"down.png",vahed/2,vahed/2);
    if(volumefirst>0){
            rect(m_renderer,8*W/10-vahed-20,2*H/3,vahed,vahed,100,200,100,1);

    texture(m_renderer , 8*W/10-vahed-20,2*H/3,"sound2.png",vahed,vahed);
    }
    else{
            rect(m_renderer,8*W/10-vahed-20,2*H/3,vahed,vahed,100,200,100,1);
       texture(m_renderer , 8*W/10-vahed-20,2*H/3,"mute2.png",vahed,vahed);
    }
         if(e->type==SDL_MOUSEBUTTONDOWN)
            {
             if((e->button.button==SDL_BUTTON_LEFT))
            {
                int x0=e->motion.x;
                int y0=e->motion.y;
                 if(x0>=8*W/10-20 && x0<=8*W/10+vahed/2-20 && y0<=2*H/3+vahed/2 && y0>=2*H/3)
                {
                    volumefirst++;
                    if(volumefirst>=30)
                        volumefirst=30;
                }
                if(x0>=8*W/10-20 && x0<=8*W/10+vahed/2-20 && y0<=2*H/3+vahed && y0>=2*H/3+vahed/2)
                {
                    volumefirst--;
                    if(volumefirst<=0)
                    {
                        volumefirst=0;

                    }

                }
            }
            }
            if(e->type==SDL_MOUSEBUTTONDOWN)
            {
             if((e->button.button==SDL_BUTTON_LEFT))
            {
                int x0=e->motion.x;
                int y0=e->motion.y;
                if(x0>=W/10+980 && y0>=H/7+40 && x0<=W/10+1020 && y0<=H/7+60)
                {
                    if(ent1==0){
                        ent1=1;
                        okgoal=1;
                        texture(m_renderer,W/10,2*H/7,"1 r.png",70,70);
                        texture(m_renderer,W/10+90,2*H/7,"2 r.png",70,70);
                        texture(m_renderer,W/10+180,2*H/7,"3 r.png",70,70);
                        texture(m_renderer,W/10+270,2*H/7,"4 r.png",70,70);
                        texture(m_renderer,W/10+360,2*H/7,"5 r.png",70,70);
                        texture(m_renderer,W/10+450,2*H/7,"6 r.png",70,70);
                        texture(m_renderer,W/10+540,2*H/7,"7 r.png",70,70);
                        texture(m_renderer,W/10+630,2*H/7,"8 r.png",70,70);
                        texture(m_renderer,W/10+720,2*H/7,"9 r.png",70,70);
                        texture(m_renderer,W/10+790,2*H/7,"1 r.png",70,70);
                        texture(m_renderer,W/10+840,2*H/7,"0 r.png",70,70);
                        for(int i=0;i<10;i++)
                        {
                            ellipse(m_renderer,W/10+i*90+38,2*H/7+90,10,10,0,0,255,sel[i]);

                        }



                    }
                    else{
                        ent1=0;
                        okgoal=0;
                            ellipse(m_renderer,W/10+1000,H/7+50,20,20,255,255,255,1);
                            ellipse(m_renderer,W/10+1000,H/7+50,20,20,0,0,255,ent1);
                                                    rect(m_renderer,W/10,2*H/7,950,110,100,200,100,1);


                    }
                }
                else if(x0>=W/10+980 && y0>=3*H/7+40 && x0<=W/10+1020 && y0<=3*H/7+60)
                {
                    if(ent2==0){
                        ent2=1;
                        oktime=1;
//                        texture(m_renderer,W/10,4*H/7,"60.png",70,70);
//                        texture(m_renderer,W/10+300,4*H/7,"90.png",70,70);
//                        texture(m_renderer,W/10+600,4*H/7,"120.png",70,70);
//
                        texture(m_renderer,W/10,4*H/7,"6 r.png",70,70);
                        texture(m_renderer,W/10+60,4*H/7,"0 r.png",70,70);
                        texture(m_renderer,W/10+300,4*H/7,"9 r.png",70,70);
                        texture(m_renderer,W/10+360,4*H/7,"0 r.png",70,70);
                        texture(m_renderer,W/10+600,4*H/7,"1 r.png",70,70);
                        texture(m_renderer,W/10+660,4*H/7,"2 r.png",70,70);
                        texture(m_renderer,W/10+720,4*H/7,"0 r.png",70,70);


                        for(int i=0;i<3;i++)
                        {
                            ellipse(m_renderer,W/10+i*300+38,4*H/7+90,10,10,0,0,255,0);

                        }
                    }

                    else
                        {
                            ent2=0;
                            oktime=0;
                            ellipse(m_renderer,W/10+1000,3*H/7+50,20,20,255,255,255,1);
                            ellipse(m_renderer,W/10+1000,3*H/7+50,20,20,0,0,255,ent2);
                             rect(m_renderer,W/10,4*H/7,800,110,100,200,100,1);

                    }
                }

                }
            }
            if(ent1){
             if(e->type==SDL_MOUSEBUTTONDOWN)
                         {
                         if((e->button.button==SDL_BUTTON_LEFT))
                        {
                          int xo=e->motion.x;
                          int yo=e->motion.y;

                            if((xo<=W/10+48) && (xo>=W/10+28) &&( yo<=2*H/7+100 )&& (yo>=2*H/7+80))
                            {
                                if(sel[0]==0){
                                for(int i=0;i<10;i++)
                                {
                                 sel[i]=0;
                               }
                                    sel[0]=1;
                                    goalwin=1;
                            ellipse(m_renderer,W/10+38,2*H/7+90,10,10,0,0,255,sel[0]);
                                }
                                else
                                {
                                    sel[0]=0;
                                    goalwin=1;
                            ellipse(m_renderer,W/10+38,2*H/7+90,10,10,255,255,255,1);
                            ellipse(m_renderer,W/10+38,2*H/7+90,10,10,0,0,255,sel[0]);

                                }
                            }
                            else if(xo<=W/10+1*90+48 && xo>=W/10+1*90+28 && yo<=2*H/7+100 && yo>=2*H/7+80)
                            {
                          if(sel[1]==0)
                          {
                            for(int i=0;i<10;i++)
                              {
                                  sel[i]=0;
                             }

                                    sel[1]=1;
                                    goalwin=2;
                            ellipse(m_renderer,W/10+1*90+38,2*H/7+90,10,10,0,0,255,sel[1]);
                                }
                                else
                                {
                                    sel[1]=0;
                                    goalwin=1;
                            ellipse(m_renderer,W/10+1*90+38,2*H/7+90,10,10,255,255,255,1);
                            ellipse(m_renderer,W/10+1*90+38,2*H/7+90,10,10,0,0,255,sel[1]);

                                }

                            }
                              else if(xo<=W/10+2*90+48 && xo>=W/10+2*90+28 && yo<=2*H/7+100 && yo>=2*H/7+80)
                            {

                                if(sel[2]==0){
                                    for(int i=0;i<10;i++)
                                    {
                                     sel[i]=0;
                                    }
                                    sel[2]=1;
                                    goalwin=3;

                            ellipse(m_renderer,W/10+2*90+38,2*H/7+90,10,10,0,0,255,sel[2]);
                                }
                                else
                                {
                                    sel[2]=0;
                                    goalwin=1;
                            ellipse(m_renderer,W/10+2*90+38,2*H/7+90,10,10,255,255,255,1);
                            ellipse(m_renderer,W/10+2*90+38,2*H/7+90,10,10,0,0,255,sel[2]);

                                }

                            }
                            else if(xo<=W/10+3*90+48 && xo>=W/10+3*90+28 && yo<=2*H/7+100 && yo>=2*H/7+80)
                            {

                                if(sel[3]==0){
                                for(int i=0;i<10;i++)
                                    {
                                          sel[i]=0;
                                    }
                                    sel[3]=1;
                                    goalwin=4;
                            ellipse(m_renderer,W/10+3*90+38,2*H/7+90,10,10,0,0,255,sel[3]);
                                }
                                else
                                {
                                    goalwin=1;
                                    sel[3]=0;
                            ellipse(m_renderer,W/10+3*90+38,2*H/7+90,10,10,255,255,255,1);
                            ellipse(m_renderer,W/10+3*90+38,2*H/7+90,10,10,0,0,255,sel[3]);

                                }

                            }
                              else if(xo<=W/10+4*90+48 && xo>=W/10+4*90+28 && yo<=2*H/7+100 && yo>=2*H/7+80)
                            {
                                if(sel[4]==0){
                                for(int i=0;i<10;i++)
                              {
                                 sel[i]=0;
                                  }
                                    sel[4]=1;
                                    goalwin=5;
                            ellipse(m_renderer,W/10+4*90+38,2*H/7+90,10,10,0,0,255,sel[4]);
                                }
                                else
                                {
                                    sel[4]=0;
                                    goalwin=1;
                            ellipse(m_renderer,W/10+4*90+38,2*H/7+90,10,10,255,255,255,1);
                            ellipse(m_renderer,W/10+4*90+38,2*H/7+90,10,10,0,0,255,sel[4]);

                                }

                            }
                              else if(xo<=W/10+5*90+48 && xo>=W/10+5*90+28 && yo<=2*H/7+100 && yo>=2*H/7+80)
                            {
                                if(sel[5]==0){
                                            for(int i=0;i<10;i++)
    {
        sel[i]=0;
    }
                                    sel[5]=1;
                                    goalwin=6;
                            ellipse(m_renderer,W/10+5*90+38,2*H/7+90,10,10,0,0,255,sel[5]);
                                }
                                else
                                {
                                    sel[5]=0;
                                    goalwin=1;
                            ellipse(m_renderer,W/10+5*90+38,2*H/7+90,10,10,255,255,255,1);
                            ellipse(m_renderer,W/10+5*90+38,2*H/7+90,10,10,0,0,255,sel[5]);

                                }

                            }
                              else if(xo<=W/10+6*90+48 && xo>=W/10+6*90+28 && yo<=2*H/7+100 && yo>=2*H/7+80)
                            {
                                if(sel[6]==0){
                                            for(int i=0;i<10;i++)
    {
        sel[i]=0;
    }
                                    sel[6]=1;
                                    goalwin=7;
                            ellipse(m_renderer,W/10+6*90+38,2*H/7+90,10,10,0,0,255,sel[6]);
                                }
                                else
                                {
                                    sel[6]=0;
                                    goalwin=1;
                            ellipse(m_renderer,W/10+6*90+38,2*H/7+90,10,10,255,255,255,1);
                            ellipse(m_renderer,W/10+6*90+38,2*H/7+90,10,10,0,0,255,sel[6]);

                                }

                            }
                              else if(xo<=W/10+7*90+48 && xo>=W/10+7*90+28 && yo<=2*H/7+100 && yo>=2*H/7+80)
                            {
                                if(sel[7]==0){
                                            for(int i=0;i<10;i++)
    {
        sel[i]=0;
    }
                                        goalwin=8;
                                    sel[7]=1;
                            ellipse(m_renderer,W/10+7*90+38,2*H/7+90,10,10,0,0,255,sel[7]);
                                }
                                else
                                {
                                    sel[7]=0;
                                    goalwin=1;
                            ellipse(m_renderer,W/10+7*90+38,2*H/7+90,10,10,255,255,255,1);
                            ellipse(m_renderer,W/10+7*90+38,2*H/7+90,10,10,0,0,255,sel[7]);

                                }

                            }
                              else if(xo<=W/10+8*90+48 && xo>=W/10+8*90+28 && yo<=2*H/7+100 && yo>=2*H/7+80)
                            {
                                if(sel[8]==0){
                                            for(int i=0;i<10;i++)
    {
        sel[i]=0;
    }
                                    sel[8]=1;
                                    goalwin=9;
                            ellipse(m_renderer,W/10+8*90+38,2*H/7+90,10,10,0,0,255,sel[8]);
                                }
                                else
                                {
                                    sel[8]=0;
                                    goalwin=1;
                            ellipse(m_renderer,W/10+8*90+38,2*H/7+90,10,10,255,255,255,1);
                            ellipse(m_renderer,W/10+8*90+38,2*H/7+90,10,10,0,0,255,sel[9]);

                                }

                            }
                            else if(xo<=W/10+9*90+48 && xo>=W/10+9*90+28 && yo<=2*H/7+100 && yo>=2*H/7+80)
                            {
                                if(sel[9]==0){
                                            for(int i=0;i<10;i++)
                               {
                                    sel[i]=0;
                            }
                                    sel[9]=1;
                                    goalwin=10;
                            ellipse(m_renderer,W/10+9*90+38,2*H/7+90,10,10,0,0,255,sel[9]);
                                }
                                else
                                {
                                    sel[9]=0;
                                    goalwin=1;
                            ellipse(m_renderer,W/10+9*90+38,2*H/7+90,10,10,255,255,255,1);
                            ellipse(m_renderer,W/10+9*90+38,2*H/7+90,10,10,0,0,255,sel[9]);

                                }

                            }

                        }
                         }
            }
            for(int i=0;i<10;i++)
            {
                if(ent1){
                if(sel[i]==0)
                {
                            ellipse(m_renderer,W/10+i*90+38,2*H/7+90,10,10,255,255,255,1);
                            ellipse(m_renderer,W/10+i*90+38,2*H/7+90,10,10,0,0,255,sel[i]);
                }
            }
            }
            if(ent2){
             if(e->type==SDL_MOUSEBUTTONDOWN)
                         {
                         if((e->button.button==SDL_BUTTON_LEFT))
                        {

                          int xo=e->motion.x;
                          int yo=e->motion.y;

                            if((xo<=W/10+40) && (xo>=W/10+28) &&( yo<=4*H/7+100 )&& (yo>=4*H/7+80))
                            {
                                if(cel[0]==0){
                                for(int i=0;i<10;i++)
                                {
                                 cel[i]=0;
                               }
                                    cel[0]=1;
                                    timegame=60;
                            ellipse(m_renderer,W/10+38,4*H/7+90,10,10,0,0,255,cel[0]);
                                }
                                else
                                {
                                    cel[0]=0;
                                    timegame=60;
                            ellipse(m_renderer,W/10+38,4*H/7+90,10,10,255,255,255,1);
                            ellipse(m_renderer,W/10+38,4*H/7+90,10,10,0,0,255,cel[0]);

                                }
                            }

                            if((xo<=W/10+300+40) && (xo>=W/10+300+28) &&( yo<=4*H/7+100 )&& (yo>=4*H/7+80))
                            {
                          if(cel[1]==0)
                          {
                            for(int i=0;i<10;i++)
                              {
                                  cel[i]=0;
                             }

                                    cel[1]=1;
                                    timegame=90;
                            ellipse(m_renderer,W/10+338,4*H/7+90,10,10,0,0,255,cel[1]);
                                }
                                else
                                {
                                    cel[1]=0;
                                    timegame=60;
                            ellipse(m_renderer,W/10+1*300+38,4*H/7+90,10,10,255,255,255,1);
                            ellipse(m_renderer,W/10+1*300+38,4*H/7+90,10,10,0,0,255,cel[1]);

                                }

                            }
                            if((xo<=W/10+648) && (xo>=W/10+638) &&( yo<=4*H/7+100 )&& (yo>=4*H/7+80))
                            {

                                if(cel[2]==0){
                                    for(int i=0;i<10;i++)
                                    {
                                     cel[i]=0;
                                    }
                                    cel[2]=1;
                                    timegame=120;

                            ellipse(m_renderer,W/10+638,4*H/7+90,10,10,0,0,255,cel[2]);
                                }
                                else
                                {
                                    cel[2]=0;
                                    timegame=60;
                            ellipse(m_renderer,W/10+638,4*H/7+90,10,10,255,255,255,1);
                            ellipse(m_renderer,W/10+638,4*H/7+90,10,10,0,0,255,cel[2]);

                                }

                            }
                        }
                         }
                   }
            for(int i=0;i<3;i++)
            {
                if(ent2){
                if(cel[i]==0)
                {
                            ellipse(m_renderer,W/10+i*300+38,4*H/7+90,10,10,255,255,255,1);
                            ellipse(m_renderer,W/10+i*300+38,4*H/7+90,10,10,0,0,255,cel[i]);
            }
            }
            }


            SDL_RenderPresent(m_renderer);
            e->type=0;

    }

//    ReloadHomepage=1;
    //SDL_RenderPresent(m_renderer);
}


void text1(SDL_Renderer *m_renderer,int x_position,int y_position, const char * text,int font,int R,int G,int B,int A ,int sizefont )
{

      textRGBA(m_renderer,x_position+100,y_position+100,text,font ,sizefont,R,G,B,A);
}
void texture(SDL_Renderer *m_renderer,int xp,int yp,string addressOfImage,int width,int height)
{
        int n = addressOfImage.length();
        char char_array[n+1];

        strcpy(char_array, addressOfImage.c_str());
        SDL_Texture *myTexture;
        myTexture = IMG_LoadTexture( m_renderer, char_array);
        int w1, h1;
        SDL_QueryTexture(myTexture, NULL, NULL, &w1, &h1);
        SDL_Rect texr1;
        texr1.x = xp;
        texr1.y = yp;
        texr1.w = width;
        texr1.h = height;
        SDL_RenderCopy( m_renderer, myTexture, NULL, &texr1);
            SDL_DestroyTexture(myTexture);
}

void rect(SDL_Renderer *Renderer, int x,int y,int w,int h,int R, int G, int B, int fill_boolian )
{
    SDL_Rect rectangle ;
    rectangle.x = x;
    rectangle.y = y;
    rectangle.w = w;
    rectangle.h = h;
    SDL_SetRenderDrawColor(Renderer, R, G, B, 255);
    if (fill_boolian==1)
        SDL_RenderFillRect(Renderer, &rectangle);
    SDL_RenderDrawRect(Renderer, &rectangle);
}

void ellipse(SDL_Renderer *Renderer, int x, int y, int Radius1, int Radius2, int R, int G, int B, int fill_boolian)
{
    if(fill_boolian==1)
        filledEllipseRGBA(Renderer,x,y,Radius1,Radius2,R,G,B,255);
    if(fill_boolian==0)
        ellipseRGBA(Renderer,x,y,Radius1,Radius2,R,G,B,255);
}

void window_color(SDL_Renderer *Renderer, int R, int G, int B)
{
    SDL_SetRenderDrawColor( Renderer, R, G, B, 255 );
    SDL_RenderClear( Renderer );
    SDL_RenderPresent( Renderer );
}

void getkey1(SDL_Renderer *m_renderer,struct pic inputbox1)
{
const  char * text ="";
int font =2;
int x_position=510;
int y_position=275;
int R=0;
int G=0;
int B=0;
int A=250;
   SDL_Event *ev = new SDL_Event();
   bool flag=true;
   player1name="";
int counter=0;
    while(flag)
    {
        if(counter>12) flag=0;
        SDL_PollEvent(ev);
        if(ev->type==SDL_MOUSEBUTTONDOWN)
        {
            if(ev->button.button == SDL_BUTTON_LEFT)
            {
                int x=ev->button.x;
                int y=ev->button.y;
//                if( (x>inputbox1.xp) && (x<(inputbox1.xp+inputbox1.w) ) && (y>inputbox1.yp) &&  (y<(inputbox1.yp+inputbox1.h) )  )
//                    getkey1(m_renderer,inputbox1,W,H);
//                else flag=0;
                if( (x>inputbox1.xp) && (x<(inputbox1.xp+inputbox1.w) ) && (y>inputbox1.yp) &&  (y<(inputbox1.yp+inputbox1.h) )  )
                    flag=1;
                else flag=0;
            }

        }
        else if(ev->type == SDL_KEYDOWN)
            {
                counter++;
                if(int(ev->key.keysym.sym)==13)
                {
                    flag=0;
                    K1toK2=true;
                }
                    switch(ev->key.keysym.sym)
                    {
                         case SDLK_a:
                            player1name+='a';
                            text=player1name.c_str();
                            text1(m_renderer,x_position+30,y_position-95,text,font,R,G,B,A,30);
                             break;
                         case SDLK_b:
                            player1name+='b';
                            text=player1name.c_str();
                            text1(m_renderer,x_position+30,y_position-95,text,font,R,G,B,A,30);
                             break;
                         case SDLK_c:
                            player1name+='c';
                            text=player1name.c_str();
                            text1(m_renderer,x_position+30,y_position-95,text,font,R,G,B,A,30);
                             break;
                        case SDLK_d:
                            player1name+='d';
                            text=player1name.c_str();
                            text1(m_renderer,x_position+30,y_position-95,text,font,R,G,B,A,30);
                             break;
                        case SDLK_e:
                            player1name+='e';
                            text=player1name.c_str();
                            text1(m_renderer,x_position+30,y_position-95,text,font,R,G,B,A,30);
                             break;
                        case SDLK_f:
                            player1name+='f';
                            text=player1name.c_str();
                            text1(m_renderer,x_position+30,y_position-95,text,font,R,G,B,A,30);
                             break;
                        case SDLK_g:
                            player1name+='g';
                            text=player1name.c_str();
                            text1(m_renderer,x_position+30,y_position-95,text,font,R,G,B,A,30);
                             break;
                        case SDLK_h:
                            player1name+='h';
                            text=player1name.c_str();
                            text1(m_renderer,x_position+30,y_position-95,text,font,R,G,B,A,30);
                             break;
                        case SDLK_i:
                            player1name+='i';
                            text=player1name.c_str();
                            text1(m_renderer,x_position+30,y_position-95,text,font,R,G,B,A,30);
                             break;
                        case SDLK_j:
                            player1name+='j';
                            text=player1name.c_str();
                            text1(m_renderer,x_position+30,y_position-95,text,font,R,G,B,A,30);
                             break;
                        case SDLK_k:
                            player1name+='k';
                            text=player1name.c_str();
                            text1(m_renderer,x_position+30,y_position-95,text,font,R,G,B,A,30);
                             break;
                        case SDLK_l:
                            player1name+='l';
                            text=player1name.c_str();
                            text1(m_renderer,x_position+30,y_position-95,text,font,R,G,B,A,30);
                             break;
                        case SDLK_m:
                            player1name+='m';
                            text=player1name.c_str();
                            text1(m_renderer,x_position+30,y_position-95,text,font,R,G,B,A,30);
                             break;
                        case SDLK_n:
                            player1name+='n';
                            text=player1name.c_str();
                            text1(m_renderer,x_position+30,y_position-95,text,font,R,G,B,A,30);
                             break;
                        case SDLK_o:
                            player1name+='o';
                            text=player1name.c_str();
                            text1(m_renderer,x_position+30,y_position-95,text,font,R,G,B,A,30);
                             break;
                        case SDLK_p:
                            player1name+='p';
                            text=player1name.c_str();
                            text1(m_renderer,x_position+30,y_position-95,text,font,R,G,B,A,30);
                             break;
                        case SDLK_q:
                            player1name+='q';
                            text=player1name.c_str();
                            text1(m_renderer,x_position+30,y_position-95,text,font,R,G,B,A,30);
                             break;
                        case SDLK_r:
                            player1name+='r';
                            text=player1name.c_str();
                            text1(m_renderer,x_position+30,y_position-95,text,font,R,G,B,A,30);
                             break;
                        case SDLK_s:
                            player1name+='s';
                            text=player1name.c_str();
                            text1(m_renderer,x_position+30,y_position-95,text,font,R,G,B,A,30);
                             break;
                        case SDLK_t:
                            player1name+='t';
                            text=player1name.c_str();
                            text1(m_renderer,x_position+30,y_position-95,text,font,R,G,B,A,30);
                             break;
                        case SDLK_u:
                            player1name+='u';
                            text=player1name.c_str();
                            text1(m_renderer,x_position+30,y_position-95,text,font,R,G,B,A,30);
                             break;

                        case SDLK_v:
                            player1name+='v';
                            text=player1name.c_str();
                            text1(m_renderer,x_position+30,y_position-95,text,font,R,G,B,A,30);
                             break;
                        case SDLK_w:
                            player1name+='w';
                            text=player1name.c_str();
                            text1(m_renderer,x_position+30,y_position-95,text,font,R,G,B,A,30);
                             break;
                        case SDLK_x:
                            player1name+='x';
                            text=player1name.c_str();
                            text1(m_renderer,x_position+30,y_position-95,text,font,R,G,B,A,30);
                             break;
                        case SDLK_y:
                            player1name+='y';
                            text=player1name.c_str();
                            text1(m_renderer,x_position+30,y_position-95,text,font,R,G,B,A,30);
                             break;

                         case SDLK_z:
                            player1name+='z';
                            text=player1name.c_str();
                            text1(m_renderer,x_position+30,y_position-95,text,font,R,G,B,A,30);
                             break;
                        case SDLK_SPACE:
                            player1name+=' ';
                            text=player1name.c_str();
                            text1(m_renderer,x_position+30,y_position-95,text,font,R,G,B,A,30);
                             break;
                         case SDLK_SLASH:
                            player1name+='/';
                            text=player1name.c_str();
                            text1(m_renderer,x_position+30,y_position-95,text,font,R,G,B,A,30);
                             break;
                          case SDLK_1:
                            player1name+='1';
                            text=player1name.c_str();
                            text1(m_renderer,x_position+30,y_position-95,text,font,R,G,B,A,30);
                             break;
                         case SDLK_2:
                            player1name+='2';
                            text=player1name.c_str();
                            text1(m_renderer,x_position+30,y_position-95,text,font,R,G,B,A,30);
                             break;
                          case SDLK_3:
                            player1name+='3';
                            text=player1name.c_str();
                            text1(m_renderer,x_position+30,y_position-95,text,font,R,G,B,A,30);
                             break;
                          case SDLK_4:
                            player1name+='4';
                            text=player1name.c_str();
                            text1(m_renderer,x_position+30,y_position-95,text,font,R,G,B,A,30);
                             break;
                          case SDLK_5:
                            player1name+='5';
                            text=player1name.c_str();
                            text1(m_renderer,x_position+30,y_position-95,text,font,R,G,B,A,30);
                             break;
                           case SDLK_6:
                            player1name+='6';
                            text=player1name.c_str();
                            text1(m_renderer,x_position+30,y_position-95,text,font,R,G,B,A,30);
                             break;
                            case SDLK_7:
                            player1name+='7';
                            text=player1name.c_str();
                            text1(m_renderer,x_position+30,y_position-95,text,font,R,G,B,A,30);
                             break;
                             case SDLK_8:
                            player1name+='8';
                            text=player1name.c_str();
                            text1(m_renderer,x_position+30,y_position-95,text,font,R,G,B,A,30);
                             break;
                          case SDLK_9:
                            player1name+='9';
                            text=player1name.c_str();
                            text1(m_renderer,x_position+30,y_position-95,text,font,R,G,B,A,30);
                             break;
                         case SDLK_0:
                            player1name+='0';
                            text=player1name.c_str();
                            text1(m_renderer,x_position+30,y_position-95,text,font,R,G,B,A,30);
                             break;

                          case SDLK_BACKSPACE:
                              player1name="";
                              ev->type=0;
                              //NamePage(m_renderer,W,H);
                              ReloadHomepage=1;
                              backhome=1;
                              startgame=0;
                              flag=0;
                              break;
                           case SDLK_ESCAPE:
                              player1name="";
                              ev->type=0;
                              //NamePage(m_renderer,W,H);
                              ReloadHomepage=1;
                              backhome=1;
                              startgame=0;
                              flag=0;
                              break;
//                            player1name=player1name.substr(0,1);
//                            text=player1name.c_str();
//                            text1(m_renderer,x_position+30,y_position-95,text,font,R,G,B,A,30);
//                             break;
                    }

            }
        SDL_RenderPresent(m_renderer);
        ev->type=0;
    }
//ofstream out;
//out.open("player.txt",ios::app);
//if(out.good())
//{
//out<<player1name<<endl;
//out.close();
//}

}

void getkey2(SDL_Renderer *m_renderer,struct pic inputbox2)
{
const  char * text ="";
int font =2;
int x_position=510;
int y_position=325;
int R=0;
int G=0;
int B=0;
int A=250;
   SDL_Event *ev = new SDL_Event();
   bool flag=true;
   player2name="";
   int counter=0;
    while(flag)
    {
        if(counter>12) flag=0;
        SDL_PollEvent(ev);
        if(ev->type==SDL_MOUSEBUTTONDOWN)
        {
            if(ev->button.button == SDL_BUTTON_LEFT)
            {
                int x=ev->button.x;
                int y=ev->button.y;
//                if( (x>inputbox2.xp) && (x<(inputbox2.xp+inputbox2.w) ) && (y>inputbox2.yp) &&  (y<(inputbox2.yp+inputbox2.h) )  )
//                    getkey2(m_renderer,inputbox2);
//                else flag=0;

                if( (x>inputbox2.xp) && (x<(inputbox2.xp+inputbox2.w) ) && (y>inputbox2.yp) &&  (y<(inputbox2.yp+inputbox2.h) )  )
                    flag=1;
                else flag=0;

            }

        }
        else if(ev->type == SDL_KEYDOWN)
            {
                counter++;
                if(int(ev->key.keysym.sym)==13) flag=0;
                    switch(ev->key.keysym.sym)
                    {
                         case SDLK_a:
                            player2name+='a';
                            text=player2name.c_str();
                            text1(m_renderer,x_position+30,y_position-95,text,font,R,G,B,A,30);
                             break;
                         case SDLK_b:
                            player2name+='b';
                            text=player2name.c_str();
                            text1(m_renderer,x_position+30,y_position-95,text,font,R,G,B,A,30);
                             break;
                         case SDLK_c:
                            player2name+='c';
                            text=player2name.c_str();
                            text1(m_renderer,x_position+30,y_position-95,text,font,R,G,B,A,30);
                             break;
                        case SDLK_d:
                            player2name+='d';
                            text=player2name.c_str();
                            text1(m_renderer,x_position+30,y_position-95,text,font,R,G,B,A,30);
                             break;
                        case SDLK_e:
                            player2name+='e';
                            text=player2name.c_str();
                            text1(m_renderer,x_position+30,y_position-95,text,font,R,G,B,A,30);
                             break;
                        case SDLK_f:
                            player2name+='f';
                            text=player2name.c_str();
                            text1(m_renderer,x_position+30,y_position-95,text,font,R,G,B,A,30);
                             break;
                        case SDLK_g:
                            player2name+='g';
                            text=player2name.c_str();
                            text1(m_renderer,x_position+30,y_position-95,text,font,R,G,B,A,30);
                             break;
                        case SDLK_h:
                            player2name+='h';
                            text=player2name.c_str();
                            text1(m_renderer,x_position+30,y_position-95,text,font,R,G,B,A,30);
                             break;
                        case SDLK_i:
                            player2name+='i';
                            text=player2name.c_str();
                            text1(m_renderer,x_position+30,y_position-95,text,font,R,G,B,A,30);
                             break;
                        case SDLK_j:
                            player2name+='j';
                            text=player2name.c_str();
                            text1(m_renderer,x_position+30,y_position-95,text,font,R,G,B,A,30);
                             break;
                        case SDLK_k:
                            player2name+='k';
                            text=player2name.c_str();
                            text1(m_renderer,x_position+30,y_position-95,text,font,R,G,B,A,30);
                             break;
                        case SDLK_l:
                            player2name+='l';
                            text=player2name.c_str();
                            text1(m_renderer,x_position+30,y_position-95,text,font,R,G,B,A,30);
                             break;
                        case SDLK_m:
                            player2name+='m';
                            text=player2name.c_str();
                            text1(m_renderer,x_position+30,y_position-95,text,font,R,G,B,A,30);
                             break;
                        case SDLK_n:
                            player2name+='n';
                            text=player2name.c_str();
                            text1(m_renderer,x_position+30,y_position-95,text,font,R,G,B,A,30);
                             break;
                        case SDLK_o:
                            player2name+='o';
                            text=player2name.c_str();
                            text1(m_renderer,x_position+30,y_position-95,text,font,R,G,B,A,30);
                             break;
                        case SDLK_p:
                            player2name+='p';
                            text=player2name.c_str();
                            text1(m_renderer,x_position+30,y_position-95,text,font,R,G,B,A,30);
                             break;
                        case SDLK_q:
                            player2name+='q';
                            text=player2name.c_str();
                            text1(m_renderer,x_position+30,y_position-95,text,font,R,G,B,A,30);
                             break;
                        case SDLK_r:
                            player2name+='r';
                            text=player2name.c_str();
                            text1(m_renderer,x_position+30,y_position-95,text,font,R,G,B,A,30);
                             break;
                        case SDLK_s:
                            player2name+='s';
                            text=player2name.c_str();
                            text1(m_renderer,x_position+30,y_position-95,text,font,R,G,B,A,30);
                             break;
                        case SDLK_t:
                            player2name+='t';
                            text=player2name.c_str();
                            text1(m_renderer,x_position+30,y_position-95,text,font,R,G,B,A,30);
                             break;
                        case SDLK_u:
                            player2name+='u';
                            text=player2name.c_str();
                            text1(m_renderer,x_position+30,y_position-95,text,font,R,G,B,A,30);
                             break;

                        case SDLK_v:
                            player2name+='v';
                            text=player2name.c_str();
                            text1(m_renderer,x_position+30,y_position-95,text,font,R,G,B,A,30);
                             break;
                        case SDLK_w:
                            player2name+='w';
                            text=player2name.c_str();
                            text1(m_renderer,x_position+30,y_position-95,text,font,R,G,B,A,30);
                             break;
                        case SDLK_x:
                            player2name+='x';
                            text=player2name.c_str();
                            text1(m_renderer,x_position+30,y_position-95,text,font,R,G,B,A,30);
                             break;
                        case SDLK_y:
                            player2name+='y';
                            text=player2name.c_str();
                            text1(m_renderer,x_position+30,y_position-95,text,font,R,G,B,A,30);
                             break;

                         case SDLK_z:
                            player2name+='z';
                            text=player2name.c_str();
                            text1(m_renderer,x_position+30,y_position-95,text,font,R,G,B,A,30);
                             break;
                        case SDLK_SPACE:
                            player2name+=' ';
                            text=player2name.c_str();
                            text1(m_renderer,x_position+30,y_position-95,text,font,R,G,B,A,30);
                             break;
                         case SDLK_SLASH:
                            player2name+='/';
                            text=player2name.c_str();
                            text1(m_renderer,x_position+30,y_position-95,text,font,R,G,B,A,30);
                             break;
                          case SDLK_1:
                            player2name+='1';
                            text=player2name.c_str();
                            text1(m_renderer,x_position+30,y_position-95,text,font,R,G,B,A,30);
                             break;
                         case SDLK_2:
                            player2name+='2';
                            text=player2name.c_str();
                            text1(m_renderer,x_position+30,y_position-95,text,font,R,G,B,A,30);
                             break;
                          case SDLK_3:
                            player2name+='3';
                            text=player2name.c_str();
                            text1(m_renderer,x_position+30,y_position-95,text,font,R,G,B,A,30);
                             break;
                          case SDLK_4:
                            player2name+='4';
                            text=player2name.c_str();
                            text1(m_renderer,x_position+30,y_position-95,text,font,R,G,B,A,30);
                             break;
                          case SDLK_5:
                            player2name+='5';
                            text=player2name.c_str();
                            text1(m_renderer,x_position+30,y_position-95,text,font,R,G,B,A,30);
                             break;
                           case SDLK_6:
                            player2name+='6';
                            text=player2name.c_str();
                            text1(m_renderer,x_position+30,y_position-95,text,font,R,G,B,A,30);
                             break;
                            case SDLK_7:
                            player2name+='7';
                            text=player2name.c_str();
                            text1(m_renderer,x_position+30,y_position-95,text,font,R,G,B,A,30);
                             break;
                             case SDLK_8:
                            player2name+='8';
                            text=player2name.c_str();
                            text1(m_renderer,x_position+30,y_position-95,text,font,R,G,B,A,30);
                             break;
                          case SDLK_9:
                            player2name+='9';
                            text=player2name.c_str();
                            text1(m_renderer,x_position+30,y_position-95,text,font,R,G,B,A,30);
                             break;
                         case SDLK_0:
                            player2name+='0';
                            text=player2name.c_str();
                            text1(m_renderer,x_position+30,y_position-95,text,font,R,G,B,A,30);
                             break;

                          case SDLK_BACKSPACE:
                              player2name="";
                              ev->type=0;
                              //NamePage(m_renderer);
                              flag=0;
                              ReloadHomepage=1;
                              backhome=1;
                              break;

                           case SDLK_ESCAPE:
                              player2name="";
                              ev->type=0;
                              //NamePage(m_renderer);
                              flag=0;
                              ReloadHomepage=1;
                              backhome=1;
                              break;
//                            player1name=player1name.substr(0,1);
//                            text=player1name.c_str();
//                            text1(m_renderer,x_position+30,y_position-95,text,font,R,G,B,A,30);
//                             break;
                    }

            }
        SDL_RenderPresent(m_renderer);
        ev->type=0;
    }

//ofstream out;
//out.open("player.txt",ios::app);
//if(out.good())
//{
//out<<player2name<<endl;
//out.close();
//}

}





