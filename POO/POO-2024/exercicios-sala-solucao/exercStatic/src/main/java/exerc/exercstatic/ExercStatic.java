/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 */

package exerc.exercstatic;

import java.util.*;

/**
 *
 * @author matheus
 */
public class ExercStatic {

    
    public static double calcularIdadeMedia(HashMap<String, Integer> mapaIdades) {
        int somaIdades = 0;
        
//        for(String nome : mapaIdades.keySet()){
//            mapaIdades.put(nome, mapaIdades.get(nome) - 5);
//        }
        for (int idade : mapaIdades.values()) {
            somaIdades += idade;
        }
        return (double) somaIdades / mapaIdades.size();
    }

    public static void main(String[] args) {
        HashMap<String, Integer> idades = new HashMap<>();
        idades.put("João", 25);
        idades.put("Maria", 30);
        idades.put("Pedro", 20);

        double idadeMedia = calcularIdadeMedia(idades);
        System.out.println("A idade média das pessoas é: " + idadeMedia);
    }
    
//    public static void main(String[] args) {
//    
//        Carro c1 = new Carro();
//        Carro c2 = new Carro();
//        Carro c3 = new Carro();
//        
//        
//        System.out.println(Carro.getNumCarros());
//        
//        c1.vendaCarro();
//        System.out.println(Carro.getNumCarros());
//
//        System.out.println(c1);
//    }
}
