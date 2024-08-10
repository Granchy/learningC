struct point {
    int x;
    int y;
};

struct rect {
    struct point pt1;
    struct point pt2;
};

struct point make_pt(int, int);

int main(int argc, char const *argv[])
{

    return 0;
}

struct point make_pt(int x, int y) {
    struct point pt;

    pt.x = x;
    pt.y = y;

    return pt;
}

/* If a large struct is to be passed to a function, it is generally more efficient ot 
pass a pointer then to copy the whole structure. cause remember when you pass a variable as an
argument, is is passed by value meaning that that is all you get, its value, so you can only play with the value,
and the variable that was used in the calling function remains unaffected by what is done to its value
in the called function.
*/