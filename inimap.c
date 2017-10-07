void inimap()  { 
  //Function: inimap() 
  //initial map size display
 
    char mapp = ' ';    // dead ==> false 
    int i, j;  
    initscr();  
    noecho();  
    curs_set(0);            // set cursor invisible  
  
    // display the map  
      for(i = 0; i < LINES; i++)  
    {   
        mvaddch(i, LEFT_EDGE, mapp);  
        mvaddch(i, RIGHT_EDGE, mapp);  
    }   
    for(j = 0; j < COLS; j++)  
    {   
        mvaddch(0, j, '=');  
        mvaddch(TOP_ROW, j, mapp);  
        mvaddch(BOT_ROW, j, mapp);  
    }  
    mvaddstr(1, 1, "Game of life");  
    mvaddstr(1, 1, "Author:  Stephane Maillot, Theo Desquin, Xiaoxuan Hu ");  
    refresh();  
}  
  

void lpDisp()  {  
//Function: lpDisp() 
//inicial display live points position   
    int numberp = 10; // innicial numbers of points 
    live.x_pos = (2,2,4,4,5,6,7,8,8,9);  
    live.y_pos = (3,2,3,4,6,3,6,8,2,3);//positions of inicial live points 
    for (int i=0; i<map.rows; i++){	 
    	mvaddch(live.y_pos[i], live.x_pos[i], LIVE_SYMBOL);/* display the food */  
	}
	refresh();  
}  
