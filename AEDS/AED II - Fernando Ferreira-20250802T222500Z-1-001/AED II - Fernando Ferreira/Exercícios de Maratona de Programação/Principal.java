import java.util.ArrayList;
import java.util.Scanner;


class Principal {
	
	private static String resolve (int car []) {
		
		String resultado = "yes";		
				
		return resultado; 
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		String resultado;
        
        String parametros[];    
        
        Scanner input = new Scanner (System.in);
        String line;
                
        boolean EndOfInput = true;      
                       
        int n;
        
        while(EndOfInput)
        {    
            line = input.nextLine();
            
            n = Integer.parseInt(line);
            
            if (n == 0) {
            	EndOfInput = false;
            }
            else {
            	
            	line = input.nextLine();

                parametros = line.split(" ");
            	
            	int car [] = new int [n];
                
                for (int i = 0; i < n; i++) 
                	car[i] = Integer.parseInt(parametros[i]);
                
                resultado = resolve (car);
                
                System.out.printf(resultado);
            	
            }
        }     
	}
}
