
int rec(int a, int b){

    if(b==1){

        return a;
    }
    else
        return (a*rec(a,b-1));
}


void main(){

    printf("%d",rec(3,4));

}
