/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 */

package alomundo;
import java.io.*;
import java.io.IOException;
import java.util.*;
/**
 *
 * @author matheus
 */
public class Alomundo {
    
//    public static void soma(int operando1, int operando2){
//        int result =  operando1 + operando2;
//        System.out.println("soma = " + result);
//    }
//    
//    public static void soma(double operando1, double operando2){
//        double result =  operando1 + operando2;
//        System.out.println("soma = " + result);
//    }

    public static <T> double soma(T op1, T op2){
        double res = -1;
        try{
        res = (double) op1 + (double) op2;
        BufferedWriter writer = new BufferedWriter(new FileWriter("pasa/teste.txt"));
        writer.write(Double.toString(res));
        writer.close();
        }        
        catch(IOException e){
            System.out.println("deu ruim na escrita!");
        }
        catch(ClassCastException e){
            System.out.println("Erro na soma");
        res = Double.parseDouble(op1.toString()) + Double.parseDouble(op2.toString());    
        }
        
        System.out.println(res);
        return res;
    }
    
    
    public static void main(String[] args) {
////        Exemplo aula encapsulamento
//        carro palio = new carro(13.2f, 1997);
//        concc empresa = new concc();
//        System.out.println("\n ano " + palio.getAno());
//        System.out.println("\nvelocidade de " + palio.getVelocidade() + "m/s\n");
//        empresa.altera(palio);
        
//        System.out.println("\n ano " + palio.getAno());
        
////        Exemplo aula metodos static
        Scanner teclado = new Scanner(System.in);
        
//        System.out.println("Retorno :" + soma("1.2","2.3"));
//        Set<String> palavras = new HashSet<>();
//        palavras.add("Lucas");
//        palavras.add("lucas");
//        palavras.add("lucas");
//        palavras.add("Thiago");
////        System.out.println(vet[2]);
//        System.out.println("Tamanho do Set:" + palavras.size());
//        
//        for(String nome : palavras){
////            if(nome.equals("Lucas"))
//            System.out.println(nome);
//        }
        
//        Exemplo exception
//        int []vet = new int[10];
//        System.out.println(vet[2]);
        System.out.println("Resultado: " + soma(4.1, 6.0));
        System.out.println("Resultado: " + soma("12", "13"));
        
        System.out.println(4/0);
    }
}
