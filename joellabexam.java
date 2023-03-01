import java.util.Scanner;

class T1 extends Thread{
	
	int elem;
    int count;
	int op;
	int pos;

    int A[];
	
	
	T1(int [] A,int count,int elem,int pos,int op){ //pos is given in 1 based index
		this.elem=elem;
		this.op=op;
		this.pos=pos;
        this.A=A;
        this.count=count;
	}
	
	public void run(){
		
		if(op==0){
			int i=count;
			
			while(i>pos-1){
				A[i]=A[i-1];
				i--;
			}
			
			A[i]=elem;

            for(i=0;i<A.length;i++){
                if(A[i]!=-1){
                    System.out.println(A[i]);
                }
            }

		}
		
		else{
			int i;
            int flag=0;
			
			for(i=0;i<A.length;i++){
				if(A[i]==elem){
                    flag=1;
					break;
				}
			}
			
			//if elem found
			if(flag==1){
				A[i]=-1;
		

                while(i<=A.length-2){
                    A[i]=A[i+1];
                    i++;
                }

                for(i=0;i<A.length;i++){
                    System.out.println(A[i]);
                }
            }

            else{
                System.out.println("Such an element does not exist! ");
            }
            
		}		
	}
}

class T2 extends Thread{
    int A[][];
    int row;
    int col;
    int elem;

    T2(int A[][],int row,int col,int elem){
        this.A=A;
        this.elem=elem;
        this.row=row;
        this.col=col;
    }

    public void run(){
        int mid_row=(row-1)/2;
        int mid_col;
        int beg_col,end_col;
        int flag=0;

        while(mid_row>=0 && mid_row<=row-1){
            beg_col=0;
            end_col=col-1;
            mid_col=(beg_col+end_col)/2;

            while(beg_col<=end_col){

                mid_col=(beg_col+end_col)/2;

                if(A[mid_row][mid_col]==elem){
                    flag=1;
                    break;
                }

                else if (A[mid_row][mid_col]>elem){
                    end_col=mid_col-1;
                }

                else{
                    beg_col=mid_col+1;
                }
            }

            if(flag==1){
                System.out.println("The element "+elem+" exists in the row"+mid_row+" and column"+mid_col);
                break;
            }
            
            else{

                if(A[mid_row][mid_col]>elem){
                    mid_row--;
                }

                else if(A[mid_row][mid_col]<elem){
                    mid_row++;
                }
            }

        }

        if(flag==0){
            System.out.println("Such an element does not exist!");
        }
    }
    
}

class Trial{
    public static void main(String[] args) {
       
        int A[]=new int[10];
        int r,c;
        int e;
        
        int max_possible;

        Scanner sc=new Scanner(System.in);

        System.out.println("Enter the number of elements to be placed in the array: ");
        max_possible=sc.nextInt();

        for(int i=0;i<max_possible;i++){
            System.out.print("Enter the number: ");
            A[i]=sc.nextInt();
        }

        System.out.print("Enter the number of rows: ");
        r=sc.nextInt();
        System.out.println();

        System.out.print("Enter the number of coloumns: ");
        c=sc.nextInt();
        System.out.println();

        int B[][]=new int[r][c];

        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                System.out.print("Enter the number: ");
                B[i][j]=sc.nextInt();
            }

            System.out.println();
        }

        T1 t1=new T1(A,max_possible,22,2,0);
        T2 t2= new T2(B, r, c, 8);

        t1.start();
        t2.start();
    }
}
