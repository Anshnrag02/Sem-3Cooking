
bool f(int mh,int md, int health , int damage){
    if(damage*health>md*mh)
        return 1;
    return 0;
}
