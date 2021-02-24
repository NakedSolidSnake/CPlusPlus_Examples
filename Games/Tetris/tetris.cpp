// #include <SFML/Graphics.hpp>
// #include <ctime>

// #define PECA_HEIGHT     18
// #define PECA_WIDTH      18

// using namespace sf;

// const int M = 20;
// const int N = 10;

// //define largura e altura do campo
// int field[M][N] = {0};

// struct Point
// {
//     int x;
//     int y;
// }a[4], b[4];

// //Matrix de peças 
// /*
// +----+----+
// |  0 |  1 | 
// +----+----+
// |  2 |  3 |
// +----+----+
// |  4 |  5 |
// +----+----+
// |  6 |  7 |
// +----+----+
// */

// //inicia a peças para matriz de peças
// int figures[7][4] = 
// {
//     1,3,5,7,    //I 
//     2,4,5,7,    //Z
//     3,5,4,6,    //S 
//     3,5,4,7,    //T 
//     2,3,5,7,    //L 
//     3,5,7,6,    //J 
//     2,3,4,5,    //O
// };

// bool check()
// {
//     for(int i = 0; i < 4; i++)
//     {
//         if(a[i].x < 0 || a[i].x >= N || a[i].y >= M)  //passou  dos limites da tela
//             return 0;   
//         else if(field[a[i].y][a[i].x])      //esta fora do campo
//             return 0;
//     }

//     return 1;
// }

// int main(int argc, char const *argv[])
// {

//     srand(time(0));

//     //Cria a tela com o titulo
//     RenderWindow window(VideoMode(320, 480), "The Game!");

//     //Carrega imagem
//     Texture t;
//     t.loadFromFile("images/tiles.png");
//     Texture background;
//     background.loadFromFile("images/background.png");
    

//     //transforma imagem em sprite
//     Sprite s(t);
//     s.setTextureRect(IntRect(0,0,PECA_WIDTH,PECA_HEIGHT)); // altura da imagem e lagura de um bloco 144 pixels / 8 blocos = 18
//     Sprite back(background);
//     back.setTextureRect(IntRect(0,0,320, 480));

//     int dx = 0;     //deslocamento em x
//     bool rotate = 0;
//     int colorNum = 1;

//     float timer = 0;
//     float delay = 0.3;

//     Clock clock;

//     while(window.isOpen())
//     {
//         float time = clock.getElapsedTime().asSeconds();
//         clock.restart();    //reinicia o relogio
//         timer += time;     //atualiza timer

//         Event e;

//         //processa eventos do jogador
//         while(window.pollEvent(e))
//         {
//             if(e.type == Event::Closed)
//                 window.close();

//             if(e.type == Event::KeyPressed)
//                 if(e.key.code == Keyboard::Up)
//                     rotate = true;
//                 else if(e.key.code == Keyboard::Left)
//                     dx = -1;
//                 else if(e.key.code == Keyboard::Right)
//                     dx = 1;
            
//         }

//         if(Keyboard::isKeyPressed(Keyboard::Down))
//             delay = 0.05;

        

//         //Movimenta na horizontal
//         for(int i = 0; i < 4; i++){
//             b[i] = a[i]; //??
//             a[i].x += dx;            
//         }

//         if(!check())
//         {
//             for(int i = 0; i < 4; i++)
//             {
//                 a[i] = b[i];
//             }
//         }

//         //Rotate 
//         if(rotate)
//         {
//             Point p = a[1]; //centro de rotação da peça 
//             for(int i = 0; i < 4; i++)
//             {
//                 //??????
//                 int x = a[i].y - p.y;
//                 int y = a[i].x - p.x;

//                 a[i].x = p.x - x;
//                 a[i].y = p.y + y;
//             }

//             if(!check())
//                 for(int i = 0; i < 4; i++){
//                     a[i] = b[i];
//                 }
//         }

//         //Tick - tempo do jogo 
//         if(timer > delay)
//         {
//             for(int i = 0; i < 4; i++){
//                 b[i] = a[i];
//                 a[i].y += 1;    //movimenta a peça no sentido vertical
//             }

//             if(!check())
//             {
//                 //constroi a peça 
//                 for(int i = 0; i < 4; i++)
//                     field[b[i].y][b[i].x] = colorNum;

//                 colorNum = 1 + rand() % 7;
//                 int n = rand() % 7;

//                for(int i = 0; i < 4; i++){
//                     a[i].x = figures[n][i] % 2;
//                     a[i].y = figures[n][i] / 2;
//                 }
//             }
            
//             timer = 0;
//         }

//         //verifica linhas completas
//         int k = M - 1;
//         for(int i = M - 1; i > 0; i--)
//         {
//             int count = 0;
//             for(int j = 0; j < N; j++)
//             {
//                 if(field[i][j])
//                     count++;
//                 field[k][j] = field[i][j];
//             }
//             if (count < N)
//                 k--;
//         }

//         //limpa as variaveis 
//         dx = 0;
//         rotate = 0; 
//         delay = 0.3;

//         //desenha a tela
//         window.clear(Color::White);
//         window.draw(back);

//         for(int i = 0; i < M; i++)
//             for(int j = 0; j < N; j++)
//             {
//                 if(field[i][j] == 0)
//                     continue;

//                 s.setTextureRect(IntRect(field[i][j]*PECA_HEIGHT, 0, PECA_WIDTH, PECA_HEIGHT));
//                 s.setPosition(j*PECA_WIDTH, i*PECA_HEIGHT);
//                 window.draw(s);                
//             }

//         for(int i = 0 ; i < 4; i++)
//         {
//             s.setPosition(a[i].x*PECA_WIDTH, a[i].y*PECA_HEIGHT);
//             window.draw(s);
//         }
//         window.display();
//     }

//     return 0;
// }


#include <SFML/Graphics.hpp>
#include <time.h>
using namespace sf;

#define PIECE_COORDS    4 

const int M = 20;
const int N = 10;



//dimensão do campo jogável
int field[M][N] = {0};

struct Point
{
    int x;
    int y;
} a[PIECE_COORDS], b[PIECE_COORDS];

//construção das peças
// +-----+-----+
// |  0  |  1  | 
// +-----+-----+
// |  2  |  3  |
// +-----+-----+
// |  4  |  5  |
// +-----+-----+
// |  6  |  7  |
// +-----+-----+

#define PIECES_AMOUNT   7
#define PIECE_LEN       4
int figures[PIECES_AMOUNT][PIECE_LEN] =
{
    1,3,5,7, // I
    2,4,5,7, // Z
    3,5,4,6, // S
    3,5,4,7, // T
    2,3,5,7, // L
    3,5,7,6, // J
    2,3,4,5, // O
};

//Verifica limites da tela
bool check()
{
   for (int i = 0; i < PIECE_COORDS; i++)
      if ((a[i].x < 0) || (a[i].x >= N) || (a[i].y >= M))   //verifica se está dentro dos limites do campo
        return 0;
      else if (field[a[i].y][a[i].x])                       //verifica se posição está vazia
        return 0;

   return 1;
};

#define SCREEN_WIDTH    320
#define SCREEN_HIGHT    480
#define GAME_TITLE      "The Game!"

int main()
{
    //Randomiza para todo o new game 
    srand(time(0));     

    //Cria tela para jogar
    RenderWindow window(VideoMode(SCREEN_WIDTH, SCREEN_HIGHT), GAME_TITLE);


    //Carrega as imagens
    Texture t1,t2,t3;
    t1.loadFromFile("images/tiles.png");
    t2.loadFromFile("images/background.png");
    t3.loadFromFile("images/frame.png");

    //Tranforma as imagens em Sprite
    Sprite s(t1), background(t2), frame(t3);

    int dx=0;         //deslocamento em x (horizontal)
    bool rotate=0;
    int colorNum=1;   //indice de cores
    float timer=0;    
    float delay=0.3;  //tempo das peças

    Clock clock;

    while (window.isOpen())
    {
        float time = clock.getElapsedTime().asSeconds();
        clock.restart();
        timer+=time;

        Event e;
        //Processa eventos da tela 
        while (window.pollEvent(e))
        {            
            if (e.type == Event::Closed)
                window.close();

            //Processa eventos do teclado
            if (e.type == Event::KeyPressed)
              if (e.key.code==Keyboard::Up)
                 rotate=true;
              else if (e.key.code==Keyboard::Left)
                 dx=-1;
              else if (e.key.code==Keyboard::Right)
                 dx=1;
        }

    if (Keyboard::isKeyPressed(Keyboard::Down))
         delay=0.05;

    //// <- Move -> ///
    for (int i=0;i<4;i++)
    { 
        b[i]=a[i];
        a[i].x+=dx;
    }
    if (!check())
        for (int i=0;i<4;i++)
            a[i]=b[i];

    //////Rotate//////
    if (rotate)
      {
        Point p = a[1]; //center of rotation
        for (int i = 0 ;i < PIECE_COORDS; i++)
          {
            int x = a[i].y-p.y;
            int y = a[i].x-p.x;
            a[i].x = p.x - x;
            a[i].y = p.y + y;
           }
        if (!check())
           for (int i = 0; i < PIECE_COORDS; i++)
             a[i]=b[i];
      }

    ///////Tick//////
    if (timer > delay)
      {
        for (int i = 0; i < PIECE_COORDS; i++)
        { 
            b[i]=a[i];
            a[i].y+=1;
        }

        if (!check())
        {
         for (int i = 0; i < PIECE_COORDS; i++)
            field[b[i].y][b[i].x]=colorNum;

         colorNum=1+rand()%7;
         int n=rand()%7;
         for (int i = 0; i < PIECE_COORDS; i++)
           {
            a[i].x = figures[n][i] % 2;
            a[i].y = figures[n][i] / 2;
           }
        }

         timer = 0;
      }

    ///////check lines//////////
    int k = M - 1;
    for (int i = (M - 1); i > 0; i--)
    {
        int count=0;
        for (int j = 0; j < N; j++)
        {
            if (field[i][j])
                count++;
            field[k][j]=field[i][j];
        }
        if (count < N)
            k--;
    }

    dx=0;
    rotate=0;
    delay=0.3;

    /////////draw//////////
    window.clear(Color::White);    
    window.draw(background);
          
    for (int i = 0; i < M; i++)
     for (int j = 0; j < N; j++)
       {
         if (field[i][j]==0)
            continue;

         s.setTextureRect(IntRect(field[i][j]*18,0,18,18));
         s.setPosition(j*18,i*18);
         s.move(28,31); //offset
         window.draw(s);
       }

    for (int i = 0; i < PIECE_COORDS; i++)
      {
        s.setTextureRect(IntRect(colorNum*18,0,18,18));
        s.setPosition(a[i].x*18,a[i].y*18);
        s.move(28,31); //offset
        window.draw(s);
      }

    window.draw(frame);
    window.display();
    }

    return 0;
}