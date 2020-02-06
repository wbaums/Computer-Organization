#define R 3
#define S 19
#define T 2

int A[R][S][T];

int
ele (long i, long j, long k)
{
  return A[R - i][1 - j][k - 1];
}

/*
1)
In general, for an array declared as: 
    T D[R][C]
array element D[i][j] is at memory address:
    &D[i][j] = Xd + L(C * i + j)
where L is the size of data type T in bytes
We can extend this equation to work for a 3 dimensional array as well.
This equation become &D[i][j][k] = Xd + L(STi + Tj + k) for an array declared
as T D[R][S][T]. 
Xd is the starting position as before. the j dimension is multiplied by the
S and T arrays because you must traverse every element of an S and T array to
traverse one position in the R array. Similarly, the j position gets multiplied
by T and then you traverse k elements in the 3rd array. Then, the i, j, and k
terms must be multiplied by L, the size an individual element in the array.
This yields the final equation: Xd + L(STi + Tj + k).

2)
To derive the constants R S T from the extended equation I started by writing out
what the assembly code was doing in each step:

        .cfi_startproc
        movl    $3, %eax                 eax  = 3
        subq    %rdi, %rax               rax  = 3 - i
        leaq    (%rax,%rax,8), %rcx      rcx = (3 - i) + 8(3 - i) ==> 9(3 -i)
        leaq    (%rax,%rcx,2), %rax      rax = (3 - i) + 2(9(3 - i) ==> 19(3 - i)
        subq    %rsi, %rax               rax = 19(3 - i) - j 
        leaq    1(%rdx,%rax,2), %rax     rax = 1 + k + 2(19(3 - i) -j)
        movl    A(,%rax,4), %eax         eax = A + 4(1 + k + 2(19(3 - i) - j))
        ret
Once we finish, we can see that the final value : A + 4(1 + k + 2(19(3 - i) - j))
is very similiar to the form we derived earlier : Xd + L(STi + Tj + k). 
A is the starting positon, and 4 is the element size. We know look at the
inside of the equation to try to figure out R S and T. We know that T multiplies
both i and j, and in the equation we can see that 2 multiplies both i and j.
Therefore T is 2. We know that S multiplies i only and in the above equation 
19 multiplies only i, so we know that S is 19. Finally, S does not multiply anything 
so we deduce that S is 3. While the original equations did not have exactly the same
form it was still possible to figure out which quantities were R S and T based on the 
similarities in the equations. 
*/
