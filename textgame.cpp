#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
  using namespace std;
    

class player
{
	private: 
	
		int health = 100;
		
		int maxDamage=30;
		int minDamage=20;
		
		int maxHealing=15;
		int minHealing=10;
	public:
	player(){
		cout<<"\n Hi my name is Letho! We need to save princess and bring her back"<<endl;
		cout<<"Here are some stats that might be useful for you going ahead "<<endl;
		
				cout<<"\n Letho`s Health "<<health<<endl;
				cout<<"\n Letho`s Attack Range is between "<<minDamage<<"-"<<maxDamage<<"."<<endl;
                cout<<"\n Letho`s Healing Range is between "<<minHealing<<"-"<<maxHealing<<"."<<endl; 

	}
	int getHealth(){
	
	return health;	
	}
	void takeDamage(int damage){
		
		
			
			if(health < 0)
		{
			cout<< "\n Ohh no, a critical hit to a player "<<endl;
			cout<< "Enemy is dealing damage of "<<damage<<" to the Letho!"<<endl;
			health=health - damage;
			cout<<"Player died...! You Lost)"<<endl;
		}
		else
		{
			cout<< "Letho`s health after receiving damage "<<health<<endl;
		}
		
		
	}
	int giveDamage(){
	
		if (health > 0){
			
				int randomDamage=(rand() % ( maxDamage - minDamage + 1) + minDamage );
				health = health + randomDamage;
				cout<<"\n Player is performing hit of "<<randomDamage<<" to the enemy "<<endl;
		}
	        
			
	};
	void heal(){
		  
		if (health > 100){
				int randomHeal =(rand() % ( maxHealing - minHealing + 1) + minHealing );
	            	health =health - randomHeal;
		cout<<"Letho healed with HP of "<<randomHeal<<endl;
		cout<<"Letho`s health after healing "<<health<<endl;

		}
		
	
	}
    
	
	
};
class enemy
{
private: 
		int health = 100;
		
		int maxDamage=30;
		int minDamage=20;
	public:
		enemy(){
			cout<<"\n Ha Ha Ha.....! I am the king of darkness don`t play with me \n I will kill you at the end of the game!!"<<endl;
			cout<<"\n Enemy`s Health "<<health<<endl;
			cout<<"\n Enemy`s Attack Range is between "<<minDamage<<"-"<<maxDamage<<"."<<endl;

		}
		int getHealth(){
	
	     return health;
		  }
	     
	void takeDamage(int damage){
			
			
				if(health < 0)
		{
			cout<< "\n Ohh no, a critical hit to a enemy "<<endl;
			cout<< "Player is dealing damage of "<<damage<<" to the enemy!"<<endl;
			health=health - damage;
			cout<<"Enemy died...! Congrats!!! You won)"<<endl;
		}
		else
		{
		cout<< "Enemy`s health after receiving damage "<<health<<endl;
		}
		
	}
		
	
	int giveDamage(){
	
		if (health > 0){
			
				int randomDamage=(rand() % ( maxDamage - minDamage + 1) + minDamage );
				health = health + randomDamage;
				cout<<"\n Enemy is performing hit of "<<randomDamage<<" to the player "<<endl;
		}
	        
	  		
	}
};	

void gameloop(player player,enemy enemy)
{
	char playerchoice;
do{
	cout<<"\n Press A to attack or H to heal"<<endl;
	cin>>playerchoice;
	if (playerchoice == 'a'|| playerchoice == 'A' )
	{
		// attacking
		enemy.takeDamage(player.giveDamage());
		if(enemy.getHealth() >0)
		{
		cout<<"\n Ha Ha Ha , It is my turn now "<<endl;
		player.takeDamage(enemy.giveDamage());	
		}
		
	}
	else if(playerchoice == 'h'||playerchoice == 'H')
	{
		//healing
		player.heal();
			if(enemy.getHealth() >0)
		{
		cout<<"\n Ha Ha Ha , It is my turn now "<<endl;
		player.takeDamage(enemy.giveDamage());	
		}
	}
	else 
	{
		cout<<"\n Invalid input!!! Please select between A and H"<<endl;
	}
	
}while(player.getHealth() > 0 && enemy.getHealth() > 0);	
}
void gamestory()
{
	cout<<"\n\n"<<endl;
	cout<<"********** STORY ABOUT THE GAME **********"<<endl;
	cout<<"In the world of Letho, you awaken as an amnesiac hero, discovering a realm plagued by a mysterious darkness.\n As you explore, you unravel your past, forge alliances, and master ancient powers to vanquish the looming evil and restore light to the land."<<endl;
	
}
int main ()
{
	
	cout<<"\t\t\t Welcome to Ella`s Text Adventure Game \n\t\t\t Here is a fun center > have fun ! "<<endl;
	gamestory();
	 
	char userinput;
	
	do{
		cout<<"\n Press S to start the game or Any key to exit the game "<<endl;
		cin>>userinput;
		
		if(userinput=='s'|| userinput=='S'){
			player playerObj;
			enemy enemyObj;
			gameloop(playerObj,enemyObj);
	
		}
		else{
			cout<<"Thanks for playing Letho! "<<endl;
		}
		
	}while(userinput=='s'|| userinput=='S');
	
	return 0;
	
}
