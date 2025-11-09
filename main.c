#include <stdio.h>

void displayArray(char (*arr)[3], int size){
        for(int x = 0; x < size; x++){
                for(int y = 0; y < size; y++){
			printf("%c ",arr[x][y]);
		}
                	printf("\n");
        }
}

void clearInputBuffer(){
	while(getchar() != '\n');
}

char getPlayerIcon(int playerNum){
	if(playerNum == 1) return 'X';
	else return '0';
}

void playerTurn(char (*arr)[3], int size, int playerNumber){
	int xLoc, yLoc;
	char playerIcon;
	int state = 0;
	
	playerIcon = getPlayerIcon(playerNumber);
	
	while(state != 1){
	scanf("%d %d", &xLoc, &yLoc);	
		if(xLoc >= 0  && xLoc <= 2  && yLoc >= 0 && yLoc <= 2){
			if(arr[xLoc][yLoc] == '*'){
				arr[xLoc][yLoc] = playerIcon;
				state = 1;
			}else{
				printf("Position used..\nTry Again\n");
				clearInputBuffer();
			}	
		}else{
			printf("Input Error\n");
			clearInputBuffer();
		}	
	}
}
int checkWin(char (*arr)[3], int size){
	int state = 0;

	//Check Rows
	for(int i = 0; i < size; i++){
		if(arr[i][0] == arr[i][1] && arr[i][1] == arr[i][2] && arr[i][0] != '*') state = 1;
	}
	
	//Check Columns
	for(int i = 0; i < size; i++){
		if(arr[0][i] == arr[1][i] && arr[1][i] == arr[2][i] && arr[0][i] != '*') state = 1;
	}
	
	//Check Diagonals
	for(int i = 0; i < size; i++){
		if(arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2] && arr[0][0] != '*') state = 1;
		if(arr[2][0] == arr[1][1] && arr[1][1] == arr[0][2] && arr[2][0] != '*') state = 1;
	}

	return state;
}


int main(void){
	//Starting Stage
	char arr[3][3] = {
		{'*','*','*'},
		{'*','*','*'},
		{'*','*','*'}
	};
	
	int size = sizeof(arr) / sizeof(arr[0]);
	int state = 0;
	int currentTurn = 1;
	
	do{
		printf("Your turn Player %d!\n",currentTurn);
		printf("Where will you go?\nEnter: X Y\n");

		displayArray(arr, size);	
		
		playerTurn(arr, size, currentTurn);
		
		if(checkWin(arr, size) == 1){
			state = 1;
		}else{
	                if(currentTurn == 1){
				currentTurn = currentTurn + 1;
			}else{
				currentTurn = currentTurn - 1;
			}		
		}	
	}while(state != 1);	
		displayArray(arr, size);
		printf("|||||||||||||||||||||||||||||||||||||||||||\n\n\t Congrats Player %d You Win! \n\n|||||||||||||||||||||||||||||||||||||||||||\n",currentTurn);
	return 0;
}
