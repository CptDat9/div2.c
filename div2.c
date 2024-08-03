#include <stdio.h>
#include <string.h>

int calculate_time(char* s) {
    int time = 2;  
    int len = strlen(s);
    
    for (int i = 1; i < len; i++) {
        if (s[i] == s[i-1]) {
            time += 1;
        } else {
            time += 2;
        }
    }
    return time;
}

void insert_and_evaluate(char* s, char new_char, int pos, char* result) {
    int len = strlen(s);
    for (int i = 0; i < pos; i++) {
        result[i] = s[i];
    }
    result[pos] = new_char;
    for (int i = pos; i < len; i++) {
        result[i + 1] = s[i];
    }
    result[len + 1] = '\0';
}

int main() {
    int t;
    scanf("%d", &t);
    
    while (t--) {
        char s[12]; 
        scanf("%s", s);
        
        int len = strlen(s);
        char best_password[12];
        int max_time = 0;
        
        for (char c = 'a'; c <= 'z'; c++) {
            for (int i = 0; i <= len; i++) {
                char new_password[12];
                insert_and_evaluate(s, c, i, new_password);
                int current_time = calculate_time(new_password);
                if (current_time > max_time) {
                    max_time = current_time;
                    strcpy(best_password, new_password);
                }
            }
        }
        
        printf("%s\n", best_password);
    }
    
    return 0;
}
