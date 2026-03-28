/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package exerc.prova;

/**
 *
 * @author matheus
 */
public class Livro {
    private String autor;
    private String titulo;
    private String genero;
    private int identificador;
    private int status;
    private String nomeReserva;
    
    public Livro ( String autor , String titulo , int identificador, String genero) {
        this.autor = autor;
        this.titulo = titulo;
        this.identificador = identificador;
        this.genero = genero.toLowerCase();
        status = 0;
    }
    
    public void buscaTitulo(String busca){
        if(this.titulo.contains(busca)){
            System.out.println("Autor: " + this.autor + "\n titulo: " + this.titulo + "\n genero: " + this.genero + "\n identificador: " + this.identificador);
            if(status == 1)
                System.out.println("\n Nome do aluno que reservou o livro: " + this.nomeReserva);
            else
                System.out.println("Livro nao reservado");
        }
    }
    
    public void buscaGenero(String busca){
        if(this.titulo.contains(busca.toLowerCase())){
            System.out.println("Autor: " + this.autor + "\n titulo: " + this.titulo + "\n genero: " + this.genero + "\n identificador: " + this.identificador);
            if(status == 1)
                System.out.println("\n Nome do aluno que reservou o livro: " + this.nomeReserva);
            else
                System.out.println("Livro nao reservado");
        }
    }
    
    public void imprimeDados(){
        System.out.println("Autor: " + this.autor + "\n titulo: " + this.titulo + "\n genero: " + this.genero + "\n identificador: " + this.identificador);
        if(status == 1)
            System.out.println("\n Nome do aluno que reservou o livro: " + this.nomeReserva);
        else
            System.out.println("Livro nao reservado");
    }
    
    public void reservarLivro(String nome){
        if(this.status == 0){
            this.status = 1;
            this.nomeReserva = nome;
        }else{
            System.out.println("Livro já reservado por " + this.nomeReserva);
        }
    }
    
    public void devolveLivro(){
        if(this.status == 1){
            this.status = 0;
            this.nomeReserva = "";
        }else{
            System.out.println("Este livro não está reservado!");
        }
    }
    
    public int consultaReserva(){
        return this.status;
    }
    
}
