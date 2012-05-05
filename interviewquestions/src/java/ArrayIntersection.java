public Object[] handleArrayIntersection(Object[] array1, Object[] array2) {
    if(array1.length == 0 || array2.length == 0){
        return new Object[0];
    }
    // the maximum possible number of intersections is the smaller array's size
    int maxPossibleLength = array1.length < array2.length ? array1.length : array2.length;
    Object[] intersectionValues = new Object[maxPossibleLength];
    int itemCount = 0;
    for(int i = 0; i < array1.length; i++){
        Object arr1Val = array1[i];
        if(contains(array2, arr1Val) && !contains(intersectionValues, arr1Val)){
            intersectionValues[itemCount] = arr1Val;
            itemCount++;
        }
    }

    // reduce the array down to only contain the intersections
    Object[] intersection = new Object[itemCount];
    for(int i = 0; i < itemCount; i++){
        intersection[i] = intersectionValues[i];
    }
    return intersection;
}


public boolean contains(Object[] newArr, Object arr1Val) {
        boolean contains = false;
        for(int i = 0; i < newArr.length; i++){
            Object val = newArr[i];
            if((val == null && arr1Val == null) || (val != null && val.equals(arr1Val))){
                contains = true;
                break;
            }
        }
        return contains;
}
