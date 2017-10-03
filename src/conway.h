int initall(void);
int enditall(void);
void switch_on(int, int);
void switch_off(int, int);
int count_neighbors();
int compute_next_state();

int get_right_col(int, int, int, int)
int get_left_col(int, int, int, int)
int get_up_col(int, int, int, int)
int get_bottom_col(int, int, int, int)

int count_neighbors(int, int, bool*, int, int)