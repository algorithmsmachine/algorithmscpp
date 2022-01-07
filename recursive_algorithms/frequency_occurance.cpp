// An array contains n numbers (not necessarily distinct) in increasing order:
// x[1] ≤ x[2] ≤ . . . ≤ x[n].
// Give a pseudocode that will compute:
// • the number of dierent numbers in the array.
// • for each of them the number of times it appears in the array


function count (int x[n])
    // number of distinct elements found index of last element.
    int elem = 1;
    // array of frequencies.
    int times[n]
    // array of distinct elements
    int distinct[n]
    int index = 1;

    times[1]=1
    distinct[1]=x[1]
    for (index = 2 to n)
        if (x[index]>x[index-1])
        // new element
        elem = elem+1;
        distinct[elem]=x[index]
        times[elem]=1;
        else
        // same element
        times[elem]=times[elem]+1
        endif
    endfor

for (int i= 1 to elem)
    print "element " distinct[i] "occurs " times[i] "times\n"