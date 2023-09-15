/* PROGRAMMING FUNDAMENTAL'S PROJECT FOR FALL 2022 BS(CS)
 * You need to define the required function in the part instructed here below.
 * Avoid making any unnecessary changes, particularly the ones you don't understand.
 * The different pieces should be defined using an array - uncomment the following code once you are done creating the array.
 * TIP: Understand thoroughly before getting started with coding.
 * */
 
//ATHAAR NAQVI          22I-1166    E


//---Piece Starts to Fall When Game Starts---//

void fallingPiece(float& timer, float& delay, int& colorNum, int& box){
    if (timer>delay){
        for (int i=0;i<4;i++){
            point_2[i][0]=point_1[i][0];
            point_2[i][1]=point_1[i][1];
            point_1[i][1]+=1;                   //How much units downward
        }
        if (!anamoly()){
          for(int i=0;i<4;i++)
           gameGrid[point_2[i][1]][point_2[i][0]]=colorNum;
           colorNum=1+rand()%7;
              
           int n=rand()%7;
        
           box=n;                   //to store the box shape
          if(n==0){ 
           for(int i=0;i<4;i++){
           point_1[i][0]=0;         //to create bomb
           point_1[i][1]=0;
           }
           
           }
           else{
           n=n-1;
          for (int i=0;i<4;i++){
                    point_1[i][0] = BLOCKS[n][i] % 2;
                    point_1[i][1] = BLOCKS[n][i] / 2;       //to create other blocks
                    }
           }
        
        
    }
    timer=0;
}
}

/////////////////////////////////////////////
///*** START CODING YOUR FUNTIONS HERE ***///
void move(int delta_x,int box){
if(box!=0){
for (int i=0;i<4;i++){
  point_2[i][0]=point_1[i][0];
   point_1[i][0]+=delta_x;               // in case of +1 it will move towards right and in case of -1 it will move towards left
}}

if (!anamoly())for(int i=0;i<4;i++){point_1[i][0]=point_2[i][0];}
}

void linesvanish(int grid[20][10],int rows, int cols, int& scorecount){


 int vanish = rows - 1;
 int count=0;
        for (int i =rows-1; i>0; i--)
        {
            for (int j = 0; j<N; j++)
            {
                if (grid[i][j]!=0) {count++;}     //to check whether there is any empty block
                grid[vanish][j] = grid[i][j];      
            }
           if (count < N)               //if yes vanish-- will make it equal to i--
             vanish--;                   // in case of no vanish will remain same and i will become i--
            count=0;                     // leading to the clearing of the line
        }
        
        scorecount++;
    

}
void Rotate(int box){
box=box-1;                       //to ensure that it's not 7

for (int i=0;i<4;i++){
                   
                   point_1[i][0] = BLOCKS[box][i] / 2;       //reverse the indexes so column 1 will become 2 and vice versa which will 
                   point_1[i][1] = BLOCKS[box][i] % 2;       // lead to rotation
                  
                    }
    
 
 
    
 if (!anamoly())for(int i=0;i<4;i++){point_1[i][0]=point_2[i][0];}  // to avoid messing up of colors in the end
}
 
 
void Bomb(int grid[20][10]){         // for bombing

        for (int i =19; i>0; i--)
        {
            for (int j = 0; j<4; j++)
            {
                            grid[i][j] = 0;   // it will make the other blocks vanish
             }}
    }


int scoreboard(int scorecount){     //to count the scores
int score=0;
if (scorecount==1){score+=10;}
else if(scorecount==2){score+=30;}
else if(scorecount==3){score+=60;}
else if(scorecount==4){score+=100;}
return score;
}

///*** YOUR FUNCTIONS END HERE ***///
/////////////////////////////////////
