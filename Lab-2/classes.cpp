#include <stdio.h>
class area{
private:
    int length;
    int breadth;
    int height;


public:
 int square(int s){
    length=s;
    int area = length * length;
    printf("Area of sqaure %d", area);
    return 0;}

int cuboid(int l,int b,int h ){
    length=l;
    breadth=b;
    height=h;

    int area = 2*(h*b + h*l+ l*b);
    printf("Area of cubiod %d", area);
    return 0; }


int cube(int l){
    length=l;
    int area = 6*length * length;
    printf("Area of cube %d", area);
  
    return 0;
}
int rectangle(int l,int b){
    length=l;
    breadth=b;
    int area = length*breadth;
    printf("Area of rectangle %d", area);
    return 0;
}
};
int main() {
    area a;
    int choice;

    while(1){
        printf("\nMenu:\n");
        printf("1) Square\n");
        printf("2) Rectangle\n");
        printf("3) cube\n");
        printf("4) cubiod\n");
        printf("5) Exit\n");
        printf("Enter your choice: ");
        scanf(" %d", &choice);

        if (choice == 1) {
            int side;
            printf("Enter side of square: ");
            scanf("%d", &side);
            a.square(side);
            
        } else if (choice == 2) {
            int length, width;
            printf("Enter length and width of rectangle: ");
            scanf("%d %d", &length, &width);
            a.rectangle(length, width);
            
        } 
        else if(choice==3){
            int side;
            scanf("%d", &side);
            a.cube(side);
            
        }
         else if (choice == 4) {
            int length, breadth, height;
            printf("Enter length and width and height of rectangle: ");
            scanf("%d %d %d", &length, &breadth, &height);
            a.cuboid(length, breadth, height);
       
         }
        else if (choice == 5) {
            printf("Exiting...\n");
            break;
        } 
        else {
            printf("Invalid choice!\n");
            continue;
        } 

    } 

    return 0;
}