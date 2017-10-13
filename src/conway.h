#define LIVE_SYMBOL		(char)0x2588 // solid block ascii code
#define BORDER_SYMBOL	'+'//(char)0x2588 // solid block ascii code
#define COLS			150
#define ROWS 			100
#define TOP_ROW     	0        
#define BOT_ROW     	ROWS +1
#define LEFT_EDGE   	0  
#define RIGHT_EDGE  	COLS +1	

struct Cell {int x; int y; bool alive;};
struct Point {int x; int y;};
struct Map {bool world[ROWS+2][COLS+2]; bool next_world[ROWS+2][COLS+2]; int rows; int cols;};

void initall(void);
void enditall(void);

void display(struct Cell*);
int count_neighbors(struct Cell*, struct Map*);

bool get_next_state (struct Cell*, struct Map*);

void inimap();
void pixel(int, int, char);
void display_cell(struct Cell*); 
void display_map(struct Map*);

void animate(int);
void draw_cell(int, int, struct Map*);
void draw_shape(int, int, int, struct Point*, struct Map*);
void draw_shape_180(int, int, int, struct Point*, struct Map*);

extern struct Point blinker[3];
extern struct Point oscillator[28];
extern struct Point cross[28];
extern struct Point galaxy[48];
extern struct Point canon[36];