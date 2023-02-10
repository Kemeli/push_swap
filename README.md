# push_swap
Because Swap_push isn’t as natural

a 42's project

This project is about ordering a stack (a) of integers, using an auxiliar stack (b).
The goal of the program is to do it using the least amount of (allowed) instructions.

The algorithms I used were: 

- radix for the big lists;
- quicksort to get the index of thoses lists;
- my own algorithm to order lists of max five numbers.

The reason why I've got the indexes from the list, was so I could use them as binary numbers in radix, since I've only got two stacks.
As they were binary, the indexes would probably have less bits to read than the original numbers. Hence it would execute faster.

-run 

```git clone git@github.com:Kemeli/push_swap.git push_swap```

```make```

```./push_swap <chosen numeric values>```

what you will see printed on the screen are the movements the program had to do to order those numbers:

- sa (swap a): Swap the first 2 elements at the top of stack a.

- pa (push a): Take the first element at the top of b and put it at the top of a.

- pb (push b): Take the first element at the top of a and put it at the top of b.

- ra (rotate a): Shift up all elements of stack a by 1.
The first element becomes the last one.

- rra (reverse rotate a): Shift down all elements of stack a by 1.
The last element becomes the first one.
