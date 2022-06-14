class MyStack{
    public Integer[] quess;

    public MyStack(int value){
        Integer[] val = new Integer[1];
        val[0] = value;
        this.quess = val;
    }
    public void add(int value){
        Integer[] val = new Integer[quess.length + 1];
        for(int j = 0; j < quess.length; j++){
            val[j] = quess[j];
        }
        val[quess.length] = value;
        this.quess = val;
    }

    public void remove(){
        Integer[] val = new Integer[quess.length - 1];
        for(int j = 0; j < quess.length - 1; j++){
            val[j] = quess[j];
        }
        this.quess = val;
    }

    public void show(){
        for(int j = 0; j < quess.length; j++){
            System.out.println(quess[j] + ", ");
        }
    }
}