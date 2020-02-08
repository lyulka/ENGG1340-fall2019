makefile:

avl_demo: avl_demo.o avl_tree.o
	g++ "avl_demo.o" "avl_tree.o" -o "avl_demo"

avl_demo.o: avl_demo.cpp 
	g++ -c "avl_demo.cpp" 

avl_tree.o: avl_tree.cpp avl_tree.h
	g++ -c "avl_tree.cpp" 

bst_demo: bst_demo.o binary_search_tree.o
	g++ "bst_demo.o" "binary_search_tree.o" -o "bst_demo"

bst_demo.o: bst_demo.cpp
	g++ -c "bst_demo.cpp"

binary_search_tree.o: binary_search_tree.cpp binary_search_tree.h
	g++ -c "binary_search_tree.cpp" 