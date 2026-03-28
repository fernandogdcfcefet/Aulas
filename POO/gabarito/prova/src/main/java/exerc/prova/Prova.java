/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 */

package exerc.prova;

import java.util.*;

/**
 *
 * @author matheus
 */
public class Prova {

    public static void main(String[] args) {
        
        Set<String> generos = new HashSet<>();
        HashMap<Integer, Livro> livros = new HashMap<>();
        Scanner teclado = new Scanner(System.in);
        int k = 1;
        int valido;
        do{
            System.out.println("Escolha uma opção");
            System.out.println("1: Listar generos de livros");
            System.out.println("2: Listar livros de um genero");
            System.out.println("3: Listar livros disponiveis para reserva");
            System.out.println("4: Adicionar livro");
            System.out.println("0: Sair");
            k = teclado.nextInt();
            switch(k){
                
                case 1:
                    System.out.println("Generos disponíveis");
                    for(String genero : generos){
                        System.out.println(genero);
                    }
                    break;
                case 2:
                    String generoBusca = "Terror";
                    System.out.println("Livros disponíveis do genero" + generoBusca);
                    for(Integer id : livros.keySet()){
                        livros.get(id).buscaGenero(generoBusca.toLowerCase());
                    }
                    break;
                case 3:
                    System.out.println("Livros disponíveis para reserva");
                    for(Integer id : livros.keySet()){
                        if(livros.get(id).consultaReserva() == 0){
                            livros.get(id).imprimeDados();
                        }
                    }
                    break;
                case 4:
                    int id;
                    
                    System.out.println("Titulo:");
                    String titulo = teclado.nextLine();
                    titulo = teclado.nextLine();
                    
                    
                    System.out.println("Genero:");
                    String genero = teclado.nextLine();
                    genero = genero.toLowerCase();
                    
                    
                    System.out.println("Autor");
                    String autor = teclado.nextLine();
                    do{
                        System.out.println("Identificador unico");
                        id = teclado.nextInt();
                        valido = 1;
                        for(Integer key : livros.keySet()){
                            if(key == id){
                                valido = 0;
                                System.out.println("Identificador em uso");
                            }
                        }
                        if (valido == 1)
                            break;
                    }while(true);
                    livros.put(id, new Livro(autor, titulo, id, genero));
                    generos.add(genero);
                    break;
            }
        }while(k != 0);
    }
}
