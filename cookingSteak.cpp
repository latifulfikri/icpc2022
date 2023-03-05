#include <stdio.h>

int main() {
    long long int testCase; scanf("%lld", &testCase);
    long long int donness[testCase]; long long int stock[testCase]; long long int order[testCase];
    int safe = 1;
    long long int time = 0;

    for (int i = 1; i<=testCase-1; i++) {
        scanf("%lld", &donness[i]);
    }
    
    for (int i = 0; i<testCase; i++) {
        scanf("%lld", &stock[i]);
    }
    
    for (int i = 0; i<testCase; i++) {
        scanf("%lld", &order[i]);
    }

    if (stock[0] >= order[0]) {
        // checkStock(stock, order, &safe, &time, testCase, donness);
        for (int i = testCase-1; i>=0; i--) {
            if (i == 0){
                break;
            }

            //printf("i: %d, time: %d, donness: %d\n", i, *time, donness[i]);
            while (stock[i] < order[i]) {
                int temp = order[i] - stock[i]; stock[i] = order[i];
                stock[i-1] -= temp;
                time += donness[i] * (temp);
            // printf("not i: %d, time: %d, donness: %d\n", i, *time, donness[i]); }
            }
        }

        if (stock[0] < order[0])
        {
            printf("-1\n");
        } else {
            printf("%lld\n", time);
        }
    }

    return 0;
}