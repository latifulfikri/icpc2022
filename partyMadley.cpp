#include <bits/stdc++.h>

using namespace std;

void print(int val,int count,int Num_student, int array[], int threshold) {
    for(int i = 0; i < Num_student; i++) { 
        for(int j = i + 1; j < Num_student; j++) {
            for(int k = j + 1; k < Num_student; k++){
                if(array[k] - array[j] <= threshold && array[j] - array[i] <= threshold && array[k] - array[i] <= threshold)
                {
                    count += 1;
                    val = array[i] + array[j] + array[k];
                }
            }
        }
    }
    if(count == 0)
    {
        printf("-1\n");
    } else {
        printf("%d %d\n", count, val);
    }
}

int main() {
    int Num_student, threshold;
    int count = 0, val = -999, temp, valtemp; scanf("%d %d", &Num_student, &threshold); getchar();
    int array[Num_student];
    
    for(int i = 0; i < Num_student; i++) {
        scanf("%d", &array[i]); getchar();
    }

    int i=0;

    do {
        for(int j = 0; j < Num_student - 1 - i; j++){
        if(array[j] > array[j + 1]){ temp = array[j]; array[j] = array[j + 1]; array[j + 1] = temp;
        } }
        i++;
    } while (i < Num_student);

    print(val,count,Num_student,array,threshold);

    return 0;
}