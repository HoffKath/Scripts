package teste; //empacota a pasta teste
import posicoes.PosicaoMapa4x4; //importa PosicaoMapa4x4 do pacote posicoes
import java.util.Scanner; //importa o metodo Scanner
import java.util.ArrayList; //importa o metodo ArrayList
//parte 3:
class AplicacaoTestaPosicoes {
  private static final int MAP_WIDTH = 4; //variavel global "tamanho do mapa"
  private static final int MAP_HEIGHT = 4; //variavel global "altura do mapa"
  
  public static void main(String [] args){
    PosicaoMapa4x4 drone1 = new PosicaoMapa4x4();//definição do primeiro drone
    Scanner sc = new Scanner(System.in); 
    boolean X = false, Y = false;
      //metodo Scanner pede do usuario as posições x e y
      do{
        System.out.printf("Drone 1 - Entre com uma posição válida para x(0, %d): ", MAP_WIDTH-1);
     	  X = drone1.setX(sc.nextInt());
        if(!X){
          System.out.printf("Valor Inválido \n");
        }

      }while(!X);
   		
      do{
        System.out.printf("Drone 1 - Entre com uma posição válida para y(0, %d): ", MAP_HEIGHT-1);
        Y = drone1.setY(sc.nextInt());
      }while(!Y);

    System.out.println("Drone1:");
    drone1.imprime(); //imprime as coodernadas do drone 1
    PosicaoMapa4x4 drone2 = new PosicaoMapa4x4(); //definição do drone 2
    X = false;
    Y = false;
    do{
      System.out.printf("Drone 2 - Entre com uma posição válida para x(0, %d): ", MAP_WIDTH-1);
       X = drone2.setX(sc.nextInt());
      if(!X){
        System.out.printf("Valor Inválido \n");
      }

    }while(!X);
     
    do{
      System.out.printf("Drone 2 - Entre com uma posição válida para y(0, %d): ", MAP_HEIGHT-1);
      Y = drone2.setY(sc.nextInt());
    }while(!Y);

    sc.close();
    System.out.println("Drone2:");
    drone2.imprime(); //imprime drone 2
    double distanciaDrone1Drone2;
    distanciaDrone1Drone2 = drone1.distancia(drone2); //calcula a distancia entre drone 1 e drone 2
    System.out.println("Distancia entre drone1 e drone2:" + distanciaDrone1Drone2);

    PosicaoMapa4x4 drone3 = new PosicaoMapa4x4(); //definição do drone 3
    drone3 = drone1.copy(); //determina que o drone 3 é uma copia do drone 1
    System.out.println("Drone3:");
    drone3.imprime(); //imprime drone 3

    //verifica as posições dos drones 
    if (PosicaoMapa4x4.estaoMesmaPosição(drone1,drone2)){
      System.out.printf("Drone1 e drone2 estão sobrepostos. \n");

    } else{
      System.out.printf("Drone1 e drone2 estão em posições diferentes. \n");
    }

    if (PosicaoMapa4x4.estaoMesmaPosição(drone1,drone3)){
      System.out.printf("Drone1 e drone3 estão sobrepostos. \n");

    } else{
      System.out.printf("Drone1 e drone3 estão em posições diferentes. \n");
    }

    if (PosicaoMapa4x4.estaoMesmaPosição(drone2,drone3)){
      System.out.printf("Drone2 e drone3 estão sobrepostos. \n");

    } else{
      System.out.printf("Drone2 e drone3 estão em posições diferentes. \n");
    }

    //determinação do ArrayList "drones" que receberá os drones definidos anteriomente
    ArrayList<PosicaoMapa4x4> drones = new ArrayList<PosicaoMapa4x4>();
    drones.add(drone1);
    drones.add(drone2);
    drones.add(drone3);

    AplicacaoTestaPosicoes.imprimeMapa(drones); //imprime o arrayList drones
  }
  

  //criação do metodo imprimeMapa
  private static void imprimeMapa(ArrayList<PosicaoMapa4x4> drones){
    boolean[][] matrix = new boolean[MAP_HEIGHT][MAP_WIDTH]; //define que matrix é uma matriz de booleanos 
    //inicializa toda a matriz com false
    for(int i=0; i < MAP_WIDTH; i++){
      for(int j = 0; j< MAP_HEIGHT; j++){
        matrix[i][j] = false;
      }
    }
    int qantDeDrones = drones.size();
    //verifica as coordenadas dos drones presentes no array "drones" e insere true na matrix nessas posições
    for(int i = 0; i < qantDeDrones; i ++){
      PosicaoMapa4x4 drone = drones.get(i);
      matrix[drone.getY()][drone.getX()] = true;
    }

    //imprime a matriz, se for true então imprime [X], se for false imprime [ ]
    for(int i= MAP_WIDTH-1; i >= 0; i--){
      for(int j = 0; j<MAP_HEIGHT; j++){
        if(matrix[i][j]){
          System.out.printf("[X]");
        }else{
          System.out.printf("[ ]");
        }
      }
      System.out.printf("\n");
    }
    
  }
  
}