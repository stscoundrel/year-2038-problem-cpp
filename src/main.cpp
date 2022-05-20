#include <iostream>

int get_current_year(int timestamp) {
    int const START_YEAR = 1970;
    int timestamp_in_years = timestamp / 60 / 60 / 24 / 365;

    return START_YEAR + timestamp_in_years;
}

int main() {
    int max_timestamp = 2147483647;
    int past_max_timestamp = max_timestamp + 1;

    int max_date = get_current_year(max_timestamp);
    int past_max_date = get_current_year(past_max_timestamp);

    printf("---------------------------------------------------------------- \n");
    printf("Should print year from max timestamp. Real value should be 2038 \n");
    printf("Max timestamp: %d \n", max_date); 
    printf("---------------------------------------------------------------- \n");
    printf("Should print year from max timestamp + 1 second. Logically it should still be 2038 \n");
    printf("Past max timestamp: %d \n", past_max_date);
    printf("Due to integer overflow, we're in 1900s. With proper date calc it would be 1901, but less-than-precise check brings us to 1902. \n");
    printf("Still far cry from 2038, which would be the 'logical' value \n");
    printf("---------------------------------------------------------------- \n");
}
