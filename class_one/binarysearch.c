Position BinarySearch(List L,ElementType X){
    int first = 1,last = L->Last;
    int ok = 0,indices;
    while(last != first){
        int center = (last+first)/2;
        if(L->Data[center] == X){indices = center;ok = 1;break;}
        else if(X < L->Data[center]){last = center-1;}
        else{first = center+1;}
    }
    if(L->Data[last] == X){ok = 1;indices = last;}
    if(ok == 1){return indices;}
    if(ok == 0){return NotFound;}
}