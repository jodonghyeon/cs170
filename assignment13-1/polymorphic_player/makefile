UNAME := $(shell uname)
ifeq ($(UNAME),Darwin)
	CXX := clang++
else
	CXX := g++
endif

CPPFLAGS :=-DNDEBUG -DTESTALL
CXXFLAGS =-O2 -std=c++17 -Wall -Wextra -Wshadow -Wnon-virtual-dtor -Wold-style-cast -Woverloaded-virtual -Wpedantic -Wconversion -Wsign-conversion -Wnull-dereference -Wdouble-promotion -Wformat=2
ifeq ($(CXX),g++)
	CXXFLAGS += -Wmisleading-indentation -Wduplicated-cond -Wduplicated-branches -Wlogical-op -Wuseless-cast
endif

BUILD_DIR := build
SOURCE_FILES := $(wildcard source/*.cpp)
OBJECT_FILES := $(patsubst source/%.cpp, $(BUILD_DIR)/%.o, $(SOURCE_FILES))

$(BUILD_DIR)/driver : $(OBJECT_FILES) | $(BUILD_DIR)
	$(CXX) $(LDFLAGS) -o $@ $(OBJECT_FILES)

$(BUILD_DIR)/%.o : source/%.cpp | $(BUILD_DIR)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -o $@ -c $<

$(BUILD_DIR):
	mkdir $(BUILD_DIR)

.PHONY: clean 00_test_simple1 01_test_simple2 02_test_list1 03_test_list2 04_test_list3 05_test_list4 06_test_load_save1 07_test_load_save2 08_test_owns1 09_test_copy 10_test_assign1 11_test_assign2 12_test_assign3 13_test_exception_handling1 14_test_exception_handling2 15_test_fight1 16_test_fight2 17_test_compare1 18_test_compare2 19_test_compare3 20_test_all

00_test_simple1: CPPFLAGS :=-DNDEBUG -DTESTSIMPLE1
00_test_simple1: $(OBJECT_FILES)
	$(CXX) $(LDFLAGS) -o $(BUILD_DIR)/$@ $(patsubst $(BUILD_DIR)/driver, $(BUILD_DIR)/driver, $^)
	./$(BUILD_DIR)/$@ > your-test.txt
	diff -y --strip-trailing-cr --suppress-common-lines your-test.txt output_files/$@.txt

01_test_simple2: CPPFLAGS :=-DNDEBUG -DTESTSIMPLE2
01_test_simple2: $(OBJECT_FILES)
	$(CXX) $(LDFLAGS) -o $(BUILD_DIR)/$@ $(patsubst $(BUILD_DIR)/driver, $(BUILD_DIR)/driver, $^)
	./$(BUILD_DIR)/$@ > your-test.txt
	diff -y --strip-trailing-cr --suppress-common-lines your-test.txt output_files/$@.txt

02_test_list1: CPPFLAGS :=-DNDEBUG -DTESTLIST1
02_test_list1: $(OBJECT_FILES)
	$(CXX) $(LDFLAGS) -o $(BUILD_DIR)/$@ $(patsubst $(BUILD_DIR)/driver, $(BUILD_DIR)/driver, $^)
	./$(BUILD_DIR)/$@ > your-test.txt
	diff -y --strip-trailing-cr --suppress-common-lines your-test.txt output_files/$@.txt

03_test_list2: CPPFLAGS :=-DNDEBUG -DTESTLIST2
03_test_list2: $(OBJECT_FILES)
	$(CXX) $(LDFLAGS) -o $(BUILD_DIR)/$@ $(patsubst $(BUILD_DIR)/driver, $(BUILD_DIR)/driver, $^)
	./$(BUILD_DIR)/$@ > your-test.txt
	diff -y --strip-trailing-cr --suppress-common-lines your-test.txt output_files/$@.txt

04_test_list3: CPPFLAGS :=-DNDEBUG -DTESTLIST3
04_test_list3: $(OBJECT_FILES)
	$(CXX) $(LDFLAGS) -o $(BUILD_DIR)/$@ $(patsubst $(BUILD_DIR)/driver, $(BUILD_DIR)/driver, $^)
	./$(BUILD_DIR)/$@ > your-test.txt
	diff -y --strip-trailing-cr --suppress-common-lines your-test.txt output_files/$@.txt

05_test_list4: CPPFLAGS :=-DNDEBUG -DTESTLIST4
05_test_list4: $(OBJECT_FILES)
	$(CXX) $(LDFLAGS) -o $(BUILD_DIR)/$@ $(patsubst $(BUILD_DIR)/driver, $(BUILD_DIR)/driver, $^)
	./$(BUILD_DIR)/$@ > your-test.txt
	diff -y --strip-trailing-cr --suppress-common-lines your-test.txt output_files/$@.txt

06_test_load_save1: CPPFLAGS :=-DNDEBUG -DTESTLOADSAVE1
06_test_load_save1: $(OBJECT_FILES)
	$(CXX) $(LDFLAGS) -o $(BUILD_DIR)/$@ $(patsubst $(BUILD_DIR)/driver, $(BUILD_DIR)/driver, $^)
	./$(BUILD_DIR)/$@ > your-test.txt
	diff -y --strip-trailing-cr --suppress-common-lines your-test.txt output_files/$@.txt

07_test_load_save2: CPPFLAGS :=-DNDEBUG -DTESTLOADSAVE2
07_test_load_save2: $(OBJECT_FILES)
	$(CXX) $(LDFLAGS) -o $(BUILD_DIR)/$@ $(patsubst $(BUILD_DIR)/driver, $(BUILD_DIR)/driver, $^)
	./$(BUILD_DIR)/$@ > your-test.txt
	diff -y --strip-trailing-cr --suppress-common-lines your-test.txt output_files/$@.txt

08_test_owns1: CPPFLAGS :=-DNDEBUG -DTESTOWNS1
08_test_owns1: $(OBJECT_FILES)
	$(CXX) $(LDFLAGS) -o $(BUILD_DIR)/$@ $(patsubst $(BUILD_DIR)/driver, $(BUILD_DIR)/driver, $^)
	./$(BUILD_DIR)/$@ > your-test.txt
	diff -y --strip-trailing-cr --suppress-common-lines your-test.txt output_files/$@.txt

09_test_copy: CPPFLAGS :=-DNDEBUG -DTESTCOPY
09_test_copy: $(OBJECT_FILES)
	$(CXX) $(LDFLAGS) -o $(BUILD_DIR)/$@ $(patsubst $(BUILD_DIR)/driver, $(BUILD_DIR)/driver, $^)
	./$(BUILD_DIR)/$@ > your-test.txt
	diff -y --strip-trailing-cr --suppress-common-lines your-test.txt output_files/$@.txt

10_test_assign1: CPPFLAGS :=-DNDEBUG -DTESTASSIGN1
10_test_assign1: $(OBJECT_FILES)
	$(CXX) $(LDFLAGS) -o $(BUILD_DIR)/$@ $(patsubst $(BUILD_DIR)/driver, $(BUILD_DIR)/driver, $^)
	./$(BUILD_DIR)/$@ > your-test.txt
	diff -y --strip-trailing-cr --suppress-common-lines your-test.txt output_files/$@.txt

11_test_assign2: CPPFLAGS :=-DNDEBUG -DTESTASSIGN2
11_test_assign2: $(OBJECT_FILES)
	$(CXX) $(LDFLAGS) -o $(BUILD_DIR)/$@ $(patsubst $(BUILD_DIR)/driver, $(BUILD_DIR)/driver, $^)
	./$(BUILD_DIR)/$@ > your-test.txt
	diff -y --strip-trailing-cr --suppress-common-lines your-test.txt output_files/$@.txt

12_test_assign3: CPPFLAGS :=-DNDEBUG -DTESTASSIGN3
12_test_assign3: $(OBJECT_FILES)
	$(CXX) $(LDFLAGS) -o $(BUILD_DIR)/$@ $(patsubst $(BUILD_DIR)/driver, $(BUILD_DIR)/driver, $^)
	./$(BUILD_DIR)/$@ > your-test.txt
	diff -y --strip-trailing-cr --suppress-common-lines your-test.txt output_files/$@.txt

13_test_exception_handling1: CPPFLAGS :=-DNDEBUG -DTESTEH1
13_test_exception_handling1: $(OBJECT_FILES)
	$(CXX) $(LDFLAGS) -o $(BUILD_DIR)/$@ $(patsubst $(BUILD_DIR)/driver, $(BUILD_DIR)/driver, $^)
	./$(BUILD_DIR)/$@ > your-test.txt
	diff -y --strip-trailing-cr --suppress-common-lines your-test.txt output_files/$@.txt

14_test_exception_handling2: CPPFLAGS :=-DNDEBUG -DTESTEH2
14_test_exception_handling2: $(OBJECT_FILES)
	$(CXX) $(LDFLAGS) -o $(BUILD_DIR)/$@ $(patsubst $(BUILD_DIR)/driver, $(BUILD_DIR)/driver, $^)
	./$(BUILD_DIR)/$@ > your-test.txt
	diff -y --strip-trailing-cr --suppress-common-lines your-test.txt output_files/$@.txt

15_test_fight1: CPPFLAGS :=-DNDEBUG -DTESTFIGHT1
15_test_fight1: $(OBJECT_FILES)
	$(CXX) $(LDFLAGS) -o $(BUILD_DIR)/$@ $(patsubst $(BUILD_DIR)/driver, $(BUILD_DIR)/driver, $^)
	./$(BUILD_DIR)/$@ > your-test.txt
	diff -y --strip-trailing-cr --suppress-common-lines your-test.txt output_files/$@.txt

16_test_fight2: CPPFLAGS :=-DNDEBUG -DTESTFIGHT2
16_test_fight2: $(OBJECT_FILES)
	$(CXX) $(LDFLAGS) -o $(BUILD_DIR)/$@ $(patsubst $(BUILD_DIR)/driver, $(BUILD_DIR)/driver, $^)
	./$(BUILD_DIR)/$@ > your-test.txt
	diff -y --strip-trailing-cr --suppress-common-lines your-test.txt output_files/$@.txt

17_test_compare1: CPPFLAGS :=-DNDEBUG -DTESTCOMPARE1
17_test_compare1: $(OBJECT_FILES)
	$(CXX) $(LDFLAGS) -o $(BUILD_DIR)/$@ $(patsubst $(BUILD_DIR)/driver, $(BUILD_DIR)/driver, $^)
	./$(BUILD_DIR)/$@ > your-test.txt
	diff -y --strip-trailing-cr --suppress-common-lines your-test.txt output_files/$@.txt

18_test_compare2: CPPFLAGS :=-DNDEBUG -DTESTCOMPARE2
18_test_compare2: $(OBJECT_FILES)
	$(CXX) $(LDFLAGS) -o $(BUILD_DIR)/$@ $(patsubst $(BUILD_DIR)/driver, $(BUILD_DIR)/driver, $^)
	./$(BUILD_DIR)/$@ > your-test.txt
	diff -y --strip-trailing-cr --suppress-common-lines your-test.txt output_files/$@.txt

19_test_compare3: CPPFLAGS :=-DNDEBUG -DTESTCOMPARE3
19_test_compare3: $(OBJECT_FILES)
	$(CXX) $(LDFLAGS) -o $(BUILD_DIR)/$@ $(patsubst $(BUILD_DIR)/driver, $(BUILD_DIR)/driver, $^)
	./$(BUILD_DIR)/$@ > your-test.txt
	diff -y --strip-trailing-cr --suppress-common-lines your-test.txt output_files/$@.txt

20_test_all: CPPFLAGS :=-DNDEBUG -DTESTALL
20_test_all: $(OBJECT_FILES)
	$(CXX) $(LDFLAGS) -o $(BUILD_DIR)/$@ $(patsubst $(BUILD_DIR)/driver, $(BUILD_DIR)/driver, $^)
	./$(BUILD_DIR)/$@ > your-test.txt
	diff -y --strip-trailing-cr --suppress-common-lines your-test.txt output_files/$@.txt

clean:
	$(RM) $(BUILD_DIR)/driver $(OBJECT_FILES)

$(BUILD_DIR)/%.o : source/%.cpp $(BUILD_DIR)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -o $@ -c $<
