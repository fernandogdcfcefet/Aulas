/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package exerc.exercstatic;

/**
 *
 * @author matheus
 */
public class Carro {
    private double preco;
    private String modelo;
    private String marca;
    private int numPortas;
    
    private static int numCarros;    
    
    public static int getNumCarros(){
        return numCarros;
    }
    
    public void vendaCarro(){
        numCarros--;
    }
    
    public Carro(){
        numCarros++;}
    
    public double getPreco() {
        return preco;}

    public void setPreco(double preco) {
        this.preco = preco;}

    public String getModelo() {
        return modelo;}

    public void setModelo(String modelo) {
        this.modelo = modelo;}

    public String getMarca() {
        return marca;}

    public void setMarca(String marca) {
        this.marca = marca;}

    public int getNumPortas() {
        return numPortas;}

    public void setNumPortas(int numPortas) {
        this.numPortas = numPortas;}
    
    @Override
    public String toString(){
        return "modelo = " + this.modelo + "-- marca = " + this.marca + "-- numero de portas = " + this.numPortas + "-- preco = " + this.preco ;
    }
    
}
