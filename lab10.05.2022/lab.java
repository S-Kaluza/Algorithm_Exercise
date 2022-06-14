public class lab{
    public static void main(String[] args){
        ArrOne arrOne = new ArrOne(0);
        ArrOne arrOne2 = new ArrOne(0);
        Ques ques = new Ques(0);
        MyStack myStack = new MyStack(0);
        System.out.println("Test stosu i kolejki");
        System.out.println("Test kolejki");
        ques.add(1);
        ques.add(2);
        ques.add(3);
        ques.show();
        System.out.println("usunięcie elementu który został dodany jako pierwszy");
        ques.remove();
        ques.show();
        System.out.println("Dodanie kolejnego elementu na końcu kolejki");
        ques.add(4);
        ques.show();
        System.out.println("Test stosu");
        System.out.println("Stos:");
        myStack.show();
        System.out.println("Dodanie elementów do stosu:");
        myStack.add(1);
        myStack.add(2);
        myStack.add(3);
        myStack.add(4);
        myStack.show();
        System.out.println("Usunięcie elementu ze stosu:");
        myStack.remove();
        myStack.show();
        System.out.println("Testy listy:");
        System.out.println("Lista:");
        arrOne.show();
        System.out.println("Dodanie elementów do listy:");
        arrOne.add(1);
        arrOne.add(2);
        arrOne.add(3);
        arrOne.add(4);
        arrOne.show();
        System.out.println("Odwracanie elementów listy:");
        arrOne.reverse();
        arrOne.show();
        System.out.println("Usuwanie kluczy z listy");
        System.out.println("W celu demonstracji dodjemy dodatkowy element 4");
        arrOne.add(4);
        arrOne.show();
        System.out.println("Usunięcie kluczy:");
        arrOne.removeKey(4);
        arrOne.show();
        System.out.println("Wstawienie ponownie elementu 4 na indeksie 2 listy");
        arrOne.insertKeyByIndex(4, 2);
        arrOne.show();
        System.out.println("Ze względu na konieczność porównywania dwóch zbiorów utworzona zostaje kolejna list");
        System.out.println("lista 2:");
        arrOne2.add(1);
        arrOne2.add(2);
        arrOne2.add(3);
        arrOne2.add(4);
        arrOne2.add(5);
        arrOne2.add(6);
        arrOne2.show();
        System.out.println("Sprawdzanie czy lista 1 należy do listy 2");
        if(arrOne.isAnElementOf(arrOne2)) System.out.println("--> Lista 1 należy do listy 2");
        else System.out.println("--> Lista 1 nie należy do listy 2");
        if(arrOne2.isAnElementOf(arrOne)) System.out.println("--> Lista 2 należy do listy 1");
        else System.out.println("--> Lista 2 nie należy do listy 1");
        System.out.println("Tworzenie listy zawierającej część wspólną listy 1 i listy 2");
        Integer[] a = arrOne.intersectionWith(arrOne2);
        for(int j = 0; j < a.length; j++){
            System.out.println(a[j]);
        }
        System.out.println("Tworzenie tablicy zawierającej sumę elementów listy 1 i listy 2");
        a = arrOne.sumWith(arrOne2);
        for(int j = 0; j < a.length; j++){
            System.out.println(a[j]);
        }
        System.out.println("Sprawdzanie czy lista 1 jest podzbiorem listy 2");
        if(arrOne.isASubsetOf(arrOne2)) System.out.println("--> Lista 1 jest podzbiorem listy 2");
        else System.out.println("--> Lista 1 nie jest podzbiorem listy 2");
        if(arrOne2.isASubsetOf(arrOne)) System.out.println("--> Lista 2 jest podzbiorem listy 2");
        else System.out.println("--> Lista 1 nie jest podzbiorem listy 1");


        





    }
}
