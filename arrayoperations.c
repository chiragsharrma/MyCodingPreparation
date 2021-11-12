#include<stdio.h>
#include<stdlib.h>

struct Array
{
    int A[15];
    int size;
    int lenght;
};

void Display(struct Array arr){
    int i;
    printf("\nELEMENTS ARE:\n");
    for(i = 0;i<arr.lenght;i++)
    printf("%d ", arr.A[i]);
}
void Append(struct Array *arr, int x){
    if(arr->lenght < arr->size)
        arr->A[arr->lenght++] = x ;
}
void insert(struct Array *arr, int index, int x)
{ 
    int i;
    if(index >= 0 && index <= arr->lenght){
        for(i=arr->lenght; i > index; i--)
            arr->A[i] =arr->A[i-1];   //shifting operation
            arr->A[index] = x;        //appended at index
            arr->lenght++;
    }
}
int Delete(struct Array *arr,int index)
{
    int x =0;
    int i;
    if(index >= 0 && index< arr->lenght)
    {
        x = arr->A[index];
        for(i = index; index< arr->lenght-1 ; i++)
           arr->A[i] = arr->A[i+1];
          arr->lenght--;
          return x;
    }
    return 0;
}
int swap(int *x, int *y){
    int temp;
    temp = *x ;
    *x = *y;
    *y = temp;
}
int Linearsearch(struct Array *arr, int key)
{
    int i;
    printf("key value is at index no: ");
    for(i = 0; i<arr->lenght; i++){
        if( key == arr->A[i]){
            swap(&arr->A[i],&arr->A[0]); //move to head and transposition two diff approaches
            return i;
        }
            
    } 
    return -1;
}
int Binarysearch(struct Array arr,int key)
{  
     int low = 0;
     int high = arr.lenght-1;
     while(low<= high){
         int mid;
         mid = (low + high) / 2;
        if(key == arr.A[mid])
            return mid;
            else if(key < arr.A[mid]){
                high = mid - 1 ;
            } 
            else
             low = mid + 1;
     }
     return -1;
}

int recursebinary(int bb[] ,int l,int h,int key)    //just recursive way of binary search.
{  while(l <= h){
    int mid;
    mid = (l+h) / 2;
    if(key == bb[mid])
    return mid;
    else if(key < bb[mid])
    return recursebinary(bb,l,mid-1,key);
    else
    return recursebinary(bb,mid+1,h,key);
}
    return -1;
}
int Get(struct Array arr, int index){
    if(index>= 0 && index<arr.lenght);
        return arr.A[index];
   return -1;     
}

int Set(struct Array *arr,int index,int x)
{
    if(index >= 0 && index< arr->lenght)
    {
        arr->A[index] = x;
    }
       // return -1;
}
int Max(struct Array arr)
{
    int max = arr.A[0];
    int i;
    for(i = 1;i<arr.lenght;i++)
    {
        if(arr.A[i] > max)
            max = arr.A[i];
    }
        return max;
}
int MIN(struct Array arr)
{
    int min = arr.A[0];
    int i;
    for(i=1;i<arr.lenght;i++)
    {
        if(arr.A[i]< min)
        min = arr.A[i];
    }
    return min;
}
int SUM(struct Array arr)
{
    int s = 0;
    int i;
    for(i=0;i<arr.lenght;i++)
    {
        s += arr.A[i];
    }
    return s;
}
int AVG(struct Array arr)
{
    return (float) SUM(arr)/arr.lenght ;
}
 void Reverse(struct Array *arr)
{   
    int *B; //will use it as auxilliary array stored in heap.(cs)
    int i, j;
    B = (int *) malloc(arr->lenght*sizeof(int));
    for(i = arr->lenght - 1, j = 0; i >=0 ; i--,j++)
        {B[j] = arr->A[i];}
    for(i = 0; i > arr->lenght; i++)
       {arr->A[i] = B[i];  }  
}
 void Reverse2( struct Array *arr){
     int i,j;
     for(i=0,j=arr->lenght-1;i<j;i++,j--)
     { 
         swap(&arr->A[i],&arr->A[j]);
     }
 }
 void insertSorted(struct Array *arr,int x)
 {  
     int i = arr->lenght - 1 ;
     if(arr->lenght == arr->size)
        return;
    while(i>=0 && arr->A[i]>x)
    {
        arr->A[i+1] = arr->A[i];
        i--;
    }
    arr->A[i+1] = x;
    arr->lenght ++;
 }
 int isSorted(struct Array arr)
 {  
     int i;
     for(i= 0; i<arr.lenght - 1;i++)
     {
         if(arr.A[i]> arr.A[i+1])
         return 0;
     }
     return 1;
 }
 void REARRANGE(struct Array *arr)
 {
     int i, j ;
     i = 0 ;
     j = arr->lenght - 1;
     while (i<j)
     {
        while(arr->A[i]<0) i++;
        while(arr->A[j]>=0) j--;
        if(i<j) swap(&arr->A[i],&arr->A[j]);
     }
     
 }
 struct Array* Merge(struct Array *arr1, struct Array *arr2)
 {
     int i,j,k;
     i = j = k = 0;
     struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));
      //created a heap memory block
      while(i<arr1->lenght && j<arr2->lenght)
      {
          if(arr1->A[i]<arr2->A[j])
            arr3->A[k++] = arr1->A[i++];
          else 
            arr3->A[k++]=arr2->A[j++];  
      }
      for(;i<arr1->lenght;i++)
        arr3->A[k++] = arr1->A[i];
      for(;j<arr2->lenght;j++)
        arr3->A[k++] = arr2->A[j];
      arr3->lenght = arr1->lenght + arr2->lenght;
      arr3->size = 10;

      return arr3 ;
 }
 struct Array* UNIONOFARRAY(struct Array *arr1, struct Array *arr2)
 {
     int i,j,k;
     i = j = k = 0;
     struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));
      //created a heap memory block
      while(i<arr1->lenght && j<arr2->lenght)
      {
          if(arr1->A[i]<arr2->A[j])
            arr3->A[k++] = arr1->A[i++];
          else if(arr1->A[j]<arr2->A[i]){
              arr3->A[k++]=arr2->A[j++];
          }
          else
          {
              arr3->A[k++] = arr1->A[i++];
              j++;
          }
              
      }
      for(;i<arr1->lenght;i++)
        arr3->A[k++] = arr1->A[i];
      for(;j<arr2->lenght;j++)
        arr3->A[k++] = arr2->A[j];
      arr3->lenght = k;
      arr3->size = 10;

      return arr3 ;
 }

struct Array* INTERSECTION(struct Array *arr1, struct Array *arr2)
 {
     int i,j,k;
     i = j = k = 0;
     struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));
      //created a heap memory block
      while(i<arr1->lenght && j<arr2->lenght)
      {
          if(arr1->A[i]<arr2->A[j])
          {
              i++;
          }
            
          else if (arr2->A[j]<arr1->A[i])
          {
              j++;
          }
          else if (arr1->A[i] == arr2->A[j])
          {
                arr3->A[k++] = arr1->A[i++];
                j++ ; 
          }
      }
      arr3->lenght = k;
      arr3->size=10;

      return arr3 ;
 }
 struct Array* DIFFERENCE(struct Array *arr1, struct Array *arr2)
 {
     int i,j,k;
     i = j = k = 0;
     struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));
      //created a heap memory block
      while(i<arr1->lenght && j<arr2->lenght)
      {
          if(arr1->A[i]<arr2->A[j])
            arr3->A[k++] = arr1->A[i++];
          else if(arr2->A[j]<arr1->A[i])
                j++;  
          else
          {
              i++;
              j++;
          }     
      }
      for(;i<arr1->lenght;i++)
      {
        arr3->A[k++] = arr1->A[i];
      }
     
      arr3->lenght = k;
      arr3->size = 10;

      return arr3 ;
 }

int main()
 {
     struct Array arr1 = { {2,3,4,5,6,8,10} ,10,7};
     //struct Array arr2 = { {6,8,9,10,15,17,18} , 10,7};
    // struct Array *arr3 ; 
    // arr3 = Merge(&arr1,&arr2);
    //arr3 = DIFFERENCE(&arr1,&arr2);
     //insert(&arr,2,10);
    // Append(&arr1,11);
    // printf("%d ",Delete(&arr,4)) ; 
    /* printf("%d\n",Linearsearch(&arr,5));*/ 
     //printf("%d\n",recursebinary(arr.A,0,arr.lenght,4));gbgngb
    // printf("%d ",Get(arr,7));
   // printf(" %d\n ",Set(&arr1,5,1));
   //printf("%d  %d ",Max(arr1),MIN(arr1));
   //printf(" \n%d ",AVG(arr));
    // Reverse2( &arr);
    //insertSorted(&arr,20);
     //printf("%d \n ",isSorted(arr));
     //REARRANGE(&arr);
     Display(arr1);
     return 0;
 }