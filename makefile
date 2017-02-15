CC = clang++
CPPFLAGS = -std=c++11

all: test1 test2 test3 test4

test1: 1_two_sum.cpp
	$(CC) $(CPPFLAGS) $< -o $@
test2: 2_add_two_numbers.cpp
	$(CC) $(CPPFLAGS) $< -o $@
test3: 3_longest_substring_without_repeating_characters.cpp
	$(CC) $(CPPFLAGS) $< -o $@
test4: 4_median_of_two_sorted_array.cpp
	$(CC) $(CPPFLAGS) $< -o $@
clean:
	rm test1 test2 test3 test4
