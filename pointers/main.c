#include <stdio.h>

/*
 * int(*foo)(int) => travel right from foo - nothing - start traveling left - thus foo is a ptr to function....
 * int(*foo(int))(int) => travel right from foo - foo is a function taking int - travel left - returning a pointer to a
 * function - travel right - taking an int and - * travel left - return an int.
 *
 * In normal case we would use typedefs:
 * -------------------------------------
 * typedef int(*ArrPtr)[5];
 * typedef ArrPtr(*RetFuncPtr)(const int * const);
 * RetFuncPtr foo(const int * const) { return 0; }
 *
 * typedef RetFuncPtr(*FooPtr)(const int * const);
 * const FooPtr p0 = foo;
 */

int(*(*foo(const int* const p))(const int * const))[5] {return 0;}

int main() {
    printf("========= START =========\n");
    {
        int (*(*(*p0)(const int * const))(const int * const))[5] = foo;
        
        typedef int (*(*(* const HaveFun)(const int * const))(const int * const))[5];
        HaveFun p1 = foo;
        
        printf("%p   %p\n", p0, p1);
    }
    
    {
        int a[5] = {1, 2, 3, 4, 5};
        for(int i = 0; i < 5; ++i) printf("%d ", a[i]);
    }
    printf("\n");
    
    int a[5] = {1, 2, 3, 4}; /* All unfilled elements are 0. Shorthand: let a[5] = {}; */
    for(int i = 0; i < 5; ++i) printf("%d ", a[i]);
    printf("\n");
    
    int(*p_arr)[5] = &a; /* Note the RHS => pointer to 1st array in possibly an array of array of ints. */
    int* p_arr_start = a; /* Note the RHS == &a[0] => pointer to first int in possibly an array of ints. */
    
    printf("%p, %p, %p, %p\n", p_arr_start, p_arr, p_arr_start + 1, p_arr + 1);
    for(int i = 0; i < 5; ++i) printf("%d %d %d\n", p_arr_start[i], p_arr[0][i], (*p_arr)[i]);
    /* Notes:
     * (*p_arr_start)[i] will not compile. *p_arr_start refers to an integer, which cannot be subscripted.
     * (*p_arr)[i] will compile because *p_arr refers to an array and then we are subscripting it.
     * p_arr[i] (== *(p_arr + i)) is however UB unless you are only reading it in which case you are reading garbage
     *                            location, i.e. wrongly treating that location as an array (unless i == 0).
     * p_arr[i][i] is UB. p_arr[0][i] is well defined == *(*(p_arr + 0) + i) == *(*p_arr + i) or (*p_arr)[i] ==
     *                                                                                      *(a + i) == a[i]
     */
    printf("\n");
}
