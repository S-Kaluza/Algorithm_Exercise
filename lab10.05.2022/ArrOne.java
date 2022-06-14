public class ArrOne{
    private Integer[] arr;
    public ArrOne(int value){
        Integer[] vv = new Integer[1];
        vv[0] = value;
        this.arr = vv;
    }
    public void show(){
        for(int j = 0; j < arr.length; j++){
            System.out.println(arr[j]);
        }
    }

    public void add(int value){
        Integer[] val = new Integer[arr.length + 1];
        for(int j = 0; j < arr.length; j++){
            val[j] = arr[j];
        }
        val[arr.length] = value;
        this.arr = val;
    }

    public void removeHead(){
        Integer[] val = new Integer[arr.length - 1];
        for(int j = 1; j < arr.length; j++){
            val[j - 1] = arr[j];
        }
        this.arr = val;
    }

    public void removeTail(){
        Integer[] val = new Integer[arr.length - 1];
        for(int j = 0; j < arr.length - 1; j++){
            val[j] = arr[j];
        }
        this.arr = val;
    }

    public int naiveSearch(int x){
        for(int j = 0; j < arr.length; j++){
            if(arr[j] == x) return j;
        }
        return -1;
    }

    public void reverse(){
        int temp;
        for(int j = 0; j < arr.length/2; j++){
            temp = arr[j];
            arr[j] = arr[arr.length - (j + 1)];
            arr[arr.length - (j + 1)] = temp;
        }
    }

    public void removeKey(int key){
        for(int j = 0; j < arr.length; j++){
            if(arr[j] == key){
                Integer[] val = new Integer[arr.length - 1];
                for(int i = 0, k = 0; i < arr.length - 1; i++, k++){
                    if(i == j){
                        k++;
                    }
                    val[i] = arr[k];
                }
                this.arr = val;
            }
        }
    }

    public void insertKeyByIndex(int key, int index){
        Integer[] val = new Integer[arr.length + 1];
        for(int j = 0, k = 0; j < arr.length; j++, k++){
            if(j == index){
                val[k] = key;
                k++;
            }
            val[k] = arr[j];
        }
        this.arr = val;
    }

    public int getElementByIndex(int index){
        return arr[index];
    }

    public int getNumberOfElements(){
        return arr.length;
    }

    public boolean isAnElementOf(ArrOne arrOne){
        if(arr.length > arrOne.getNumberOfElements()) return false;
        boolean ps = false;
        for(int j = 0; j < arr.length; j++){
            ps = false;
            for(int i = 0; i < arrOne.getNumberOfElements(); i++){
                if(arrOne.getElementByIndex(i) == arr[j]) ps = true;
            }
            if(!ps) return false;
        }
        return true;
    }

    public Integer[] intersectionWith(ArrOne arrOne){
        Integer[] val = new Integer[0];
        for(int j = 0; j < arr.length; j++){
            for(int i = 0; i < arrOne.getNumberOfElements(); i++){
                if(arr[j] == arrOne.getElementByIndex(i)){
                    Integer[] temp = new Integer[val.length + 1];
                    for(int k = 0; k < val.length; k++){
                        temp[k] = val[k];
                    }
                    temp[val.length] = arr[j];
                    val = temp;
                }
            }
        }
        return val;
    }

    public Integer[] sumWith(ArrOne arrOne){
        Integer[] val = new Integer[arr.length + arrOne.getNumberOfElements()];
        for(int j = 0; j < arr.length; j++){
            val[j] = arr[j];
        }
        for(int j = arr.length, k = 0; j < arr.length + arrOne.getNumberOfElements(); j++, k++){
            val[j] = arrOne.getElementByIndex(k);
        }
        return val;
    }

    public boolean isASubsetOf(ArrOne arrOne){
        if(arr.length > arrOne.getNumberOfElements()) return false;
        int number = 0;
        for(int j = 0; j < arr.length; j++){
            for(int i = 0; i < arrOne.getNumberOfElements(); i++){
                if(arr[j] == arrOne.getElementByIndex(i)){
                    number++;
                }
            }
        }
        if(number == arr.length) return true;
        else return false;
    }

}