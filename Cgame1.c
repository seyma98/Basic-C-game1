#include<stdio.h>

int compare(char *str1,char *str2){
int flag;

while(*str1!='\0'||*str2!='\0'){

if(*str1==*str2){flag=1;
str1++;
str2++;
}

else{
flag=0;
break;
}
}
return flag;
}//the end of compare function

void PrintMaze(int r,int c,char arr[r][c]){
int i,j;
for(i=0;i<r;i++){
for(j=0;j<c;j++){
printf("%c",arr[i][j]);
}
printf("\n");
}
printf("\n");
}//the end of print func

int isItNumber(char *str){
if(compare(str,"0")||compare(str,"1")||compare(str,"2")||compare(str,"3")||compare(str,"4")||compare(str,"5")||compare(str,"6")||compare(str,"7")||compare(str,"8")||compare(str,"9")||compare(str,"10"))
return 1;
else
return 0;
}

int ConvertIntoNumber(char *str){
if(compare(str,"0")){return 0;}
else if(compare(str,"1")){return 1;}
else if(compare(str,"2")){return 2;}
else if(compare(str,"3")){return 3;}
else if(compare(str,"4")){return 4;}
else if(compare(str,"5")){return 5;}
else if(compare(str,"6")){return 6;}
else if(compare(str,"7")){return 7;}
else if(compare(str,"8")){return 8;}
else if(compare(str,"9")){return 9;}
else if(compare(str,"10")){return 10;}
}//convert func

int main(){
int i,j;
int amount;
int row,column;
int in_x,in_y;
int fin_x,fin_y;
char s,f;
char condition[10];
//row-column-positions
scanf("%d%d",&row,&column);
scanf(" %c%d%d",&s,&in_x,&in_y);
scanf(" %c%d%d",&f,&fin_x,&fin_y);

char maze[row][column];
int maze$[row][column];

for(i=0;i<row;i++){
for(j=0;j<column;j++){
if(i==0){maze[i][j]='*';}
else if(i==row-1){maze[i][j]='*';}
else if(j==0){maze[i][j]='*';}
else if(j==column-1){maze[i][j]='*';}
else{maze[i][j]=' ';}

maze$[i][j]=0;
}
}

maze[in_x][in_y]='O';
maze[fin_x][fin_y]=' ';

scanf(" %s",condition);


//************maze-content***************
while(1){
if(compare(condition,"end"))
break;

if(compare(condition,"b")){
scanf("%d%d",&i,&j);
if((i>=0)&&(j>=0)&&(i<row)&&(j<column)){maze[i][j]='*';}
scanf(" %s",condition);
}//b


else if(compare(condition,"$")){
scanf("%d%d",&i,&j);
if((i>=0)&&(j>=0)&&(i<row)&&(j<column)){
maze[i][j]='$';
scanf(" %d",&amount);
maze$[i][j]=amount;
scanf(" %s",condition);
}
}//$


else if(compare(condition,"X")){
scanf("%d%d",&i,&j);
if((i>=0)&&(j>=0)&&(i<row)&&(j<column)){maze[i][j]='X';}
scanf(" %s",condition);
}//x


}//while-maze content

PrintMaze(row,column,maze);


//******************DIRECTIONS***************************

char direction;
int x=in_x;
int y=in_y;
int point=0;
while(1){

if(scanf("%c",&direction)==EOF){
printf("YOU COULD NOT REACH THE FINAL POSITION :(\nGAME IS OVER!\n");
PrintMaze(row,column,maze);
break;
}


if(direction=='u'){
x--;

if(x==fin_x&&y==fin_y){
maze[x][y]='O';
maze[x+1][y]=' ';
printf("CONGRATS! YOU GOT %d BONUS:)\n",point);
PrintMaze(row,column,maze);
break;}//final

if(maze[x][y]=='$'){
maze[x][y]='O';
maze[x+1][y]=' ';
printf("YOU GOT %d $.\n",maze$[x][y]);
PrintMaze(row,column,maze);
point+=maze$[x][y];
}//$$

else if(maze[x][y]=='X'){

printf("YOU MET WITH THE ENEMY AND LOST THE GAME :(\nGAME IS OVER!\n");
PrintMaze(row,column,maze);
break;
}//enemy(X)


else if(maze[x][y]=='*'){x++;
printf("INVALID MOVE. TRY ANOTHER DIRECTION!\n");
PrintMaze(row,column,maze);
}//barier(*)

else{
maze[x][y]='O';
maze[x+1][y]=' ';
PrintMaze(row,column,maze);
}
}//u


else if(direction=='d'){

x++;

if(x==fin_x&&y==fin_y){
maze[x][y]='O';
maze[x-1][y]=' ';
printf("CONGRATS! YOU GOT %d BONUS:)\n",point);
PrintMaze(row,column,maze);
break;}//final

if(maze[x][y]=='$'){
maze[x][y]='O';
maze[x-1][y]=' ';
printf("YOU GOT %d $.\n",maze$[x][y]);
PrintMaze(row,column,maze);
point+=maze$[x][y];
}//$$

else if(maze[x][y]=='X'){

printf("YOU MET WITH THE ENEMY AND LOST THE GAME :(\nGAME IS OVER!\n");
PrintMaze(row,column,maze);
break;
}//enemy(X)


else if(maze[x][y]=='*'){x--;
printf("INVALID MOVE. TRY ANOTHER DIRECTION!\n");
PrintMaze(row,column,maze);
}//barier(*)

else{
maze[x][y]='O';
maze[x-1][y]=' ';

PrintMaze(row,column,maze);}

}//d


else if(direction=='r'){

y++;

if(x==fin_x&&y==fin_y){
maze[x][y]='O';
maze[x][y-1]=' ';
printf("CONGRATS! YOU GOT %d BONUS:)\n",point);
PrintMaze(row,column,maze);
break;}//final

if(maze[x][y]=='$'){
maze[x][y]='O';
maze[x][y-1]=' ';
printf("YOU GOT %d $.\n",maze$[x][y]);
PrintMaze(row,column,maze);
point+=maze$[x][y];
}//$$

else if(maze[x][y]=='X'){

printf("YOU MET WITH THE ENEMY AND LOST THE GAME :(\nGAME IS OVER!\n");
PrintMaze(row,column,maze);
break;
}//enemy(X)


else if(maze[x][y]=='*'){y--;
printf("INVALID MOVE. TRY ANOTHER DIRECTION!\n");
PrintMaze(row,column,maze);
}//barier(*)

else{
maze[x][y]='O';
maze[x][y-1]=' ';

PrintMaze(row,column,maze);}
}//r


else if(direction=='l'){

y--;

if(x==fin_x&&y==fin_y){
maze[x][y]='O';
maze[x][y+1]=' ';
printf("CONGRATS! YOU GOT %d BONUS:)\n",point);
PrintMaze(row,column,maze);
break;}//final

if(maze[x][y]=='$'){
maze[x][y]='O';
maze[x][y+1]=' ';
printf("YOU GOT %d $.\n",maze$[x][y]);
PrintMaze(row,column,maze);
point+=maze$[x][y];
}//$$

else if(maze[x][y]=='X'){

printf("YOU MET WITH THE ENEMY AND LOST THE GAME :(\nGAME IS OVER!\n");
PrintMaze(row,column,maze);
break;
}//enemy(X)


else if(maze[x][y]=='*'){y++;
printf("INVALID MOVE. TRY ANOTHER DIRECTION!\n");
PrintMaze(row,column,maze);
}//barier(*)

else{
maze[x][y]='O';
maze[x][y+1]=' ';
PrintMaze(row,column,maze);}
}//l


else if(direction=='q'){
printf("YOU COULD NOT REACH THE FINAL POSITION :(\nGAME IS OVER!\n");
PrintMaze(row,column,maze);
break;
}//q


}//the end of while


return 0;}
