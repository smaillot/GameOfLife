struct Cell {int x; int y; bool alive;};
struct Map {bool** world[10][10]; bool** next_world[10][10]; int rows; int cols;};

int initall(void);
int enditall(void);
<<<<<<< HEAD
void switch_on(int, int);
void switch_off(int, int);
int count_neighbors();
int compute_next_state();

int get_right_col(int, int, int, int)
int get_left_col(int, int, int, int)
int get_up_col(int, int, int, int)
int get_bottom_col(int, int, int, int)

int count_neighbors(int, int, bool*, int, int)
=======

void display(struct Cell*);
int count_neighbors(struct Cell*, struct Map*);

bool get_next_state (struct Cell*, struct Map*);
>>>>>>> function_law
