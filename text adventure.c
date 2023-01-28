#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <windows.h>


void encounter(char place[], int * STR ,int* INT,int* MAXHP,int * CURRHP,char * JOB, int * ARM,char * weapon){
	
	char choice;
	bool escape=false;
	int random; //for encounter generation
	int randdmg; //for damage
	char guess[50]; //for the riddler
	int i;//for "for"
	bool guesscorrect=false;//for the riddler
	bool escape_in_second_while = false;//break the while inside the while inside the switch
	int intchoice;

	
	if (strncmp(place,"Castle",50)==0){
		printf("After a few minutes of travel you come upon an old, abandoned \ncastle. Ruins, "
		"remnants of ages long past, and riches long forgotten. Do you want to take some time,\n"
		"look around the place, see if you can find anything of value? [y/n]\n");
		
		while (1){
		scanf("%1c",&choice);
		while ( getchar() != '\n' );
		switch(choice){
			case 'i':
			case 'I':
				printf("You are a %s.\nHP: %d/%d\nSTR: %d\nINT: %d\nArmor: %d\nWeapon damage: %s\n",JOB,*CURRHP,*MAXHP,*STR,*INT,*ARM,weapon);
				break;
			case 'y':
			case 'Y':
				if(strncmp(JOB,"Warrior",50)==0){
					printf("You decide to check the place out. After quite some time throwing stone around, "
					"you come across a\ncellar door, hidden between the rubble. You lift with all your might ");
				}
				else if(strncmp(JOB,"Mage",50)==0){
					printf("You decide to check the place out. After quite some time magically throwing stone around, "
					"you come across a\ncellar door, hidden between the rubble. You lift it with your mind ");
				}
				printf("and manage to open it.\nIn the middle of the cellar lies an unlocked chest. You approach, "
				"and open it. ");
				random=rand() % 10;
					
				if (random<4){ //40% chance it is not trapped
					printf("Inside you find ");
				}
				else {
					randdmg=rand() % 2 + 3; //the trap does 3-5 dmg
					*CURRHP=*CURRHP-randdmg; //we reduce it from currhp
					printf("It is trapped!\nFumes excape from the chest dealing %d damage to you! "
					"(HP:%d/%d). ",randdmg,*CURRHP,*MAXHP);
					printf("Inside you find ");
				}
				random=rand() % 4;//generates a reward
				
				
				switch (random){
					case 0://we give a potion they can use depending on the class
						if(strncmp(JOB,"Warrior",50)==0){
							printf("a potion of\nstrength. Strength increases by 2.\n");
							*STR+=2;
						}
						else if(strncmp(JOB,"Mage",50)==0){
							printf("a potion of\nintelligence. Intelligence increases by 2.\n");
							*INT+=2;
						}	
						
						break;
					case 1:
						printf("a potion of health.\nMAX HP increases by 5.\n");
						*CURRHP+=5;
						*MAXHP+=5;
						break;
					case 2:
						printf("an\nupgrade to your armor. Armor increases by 1.\n");
						*ARM=*ARM+1;
						break;
					case 3:
						printf("nothing of value.\nWhat a waste of time.\n");
						break;
					case 4:
						printf("an\nupgrade to your weapon.");
						if(strncmp(weapon,"d12",50)==0){//if the weapon is max we dont do anything
							printf(" Unfortunately the weapon cannot be upgraded further.\n");
						}
						else//else we upgrade it
							printf(" Weapon damage increases by 2.\n");
							if(strncmp(weapon,"d6",50)==0){
								sprintf(weapon,"d8");
							}
							else if(strncmp(weapon,"d8",50)==0){
								sprintf(weapon,"d10");
							}
							else if(strncmp(weapon,"d10",50)==0){
								sprintf(weapon,"d12");
							}
						
						break;
						
				}
				escape=true;
				break;
			case 'n':
			case 'N':
				printf("You leave, wondering what treasure still lies under the rubble.\n");
				escape=true;	
				break;
			default:
				printf("Invalid Input. Please press y or n.\n");
				break;
		}
		if (escape)
			break;
		}
	}
	else if(strncmp(place,"Anvil",50)==0){
		printf("Following the road you come across an anvil engulfed in flames, in the\nmiddle of the forest. "
		"The flames do not appear to set the nearby grass on fire.\nDo you touch your weapon on the magical anvil?[y/n]\n");
		
		while (1){
			scanf("%1c",&choice);
			while ( getchar() != '\n' );
			switch(choice){
				case 'i':
				case 'I':
					printf("You are a %s.\nHP: %d/%d\nSTR: %d\nINT: %d\nArmor: %d\nWeapon damage: %s\n",JOB,*CURRHP,*MAXHP,*STR,*INT,*ARM,weapon);
					break;
				case 'y':
				case 'Y':
					randdmg=rand() % 2 + 3; //the anvil does 3-5 dmg
					*CURRHP=*CURRHP-randdmg; //we reduce it from currhp
					printf("As you touch your weapon on the anvil an enourmous flame lashes out from within and\n"
					"engulfs you. It burns all over but you fight through the pain. The flames deal %d damage to you. "
					"(HP:%d/%d).\n",randdmg,*CURRHP,*MAXHP);
					//upgrade weapon code
					if(strncmp(weapon,"d12",50)==0){
							printf("Unfortunately the weapon cannot be upgraded further.\n");
					}
					else{
						printf("Weapon damage increases by 2.\n");
						if(strncmp(weapon,"d6",50)==0){
							sprintf(weapon,"d8");
						}
						else if(strncmp(weapon,"d8",50)==0){
							sprintf(weapon,"d10");
						}
						else if(strncmp(weapon,"d10",50)==0){
							sprintf(weapon,"d12");
						}
					}
					escape=true;
					break;
				case 'n':
				case 'N':
					printf("You do not trust the look of this anvil so you leave.\n");
					escape=true;
					break;
				default:
					printf("Invalid Input. Please press y or n.\n");
					break;
			}
			if(escape)
				break;
		}
	}
	
	else if(strncmp(place,"Shrine",50)==0){
		printf("As you walk further down the road, the sky seems to darken.\nThe path twists and turns, "
		"and your legs seem to move on their own. After what feels like hours,\nyou come upon a shrine "
		"to some sort of old, dark God. The shrine exudes malice and hatred, and the\ndagger that you "
		"see in front of you demands sacrifice. Do you offer your blood to the entity? [y/n]\n");
		
		while (1){
			scanf("%1c",&choice);
			while ( getchar() != '\n' );
			switch(choice){
				case 'i':
				case 'I':
					printf("You are a %s.\nHP: %d/%d\nSTR: %d\nINT: %d\nArmor: %d\nWeapon damage: %s\n",JOB,*CURRHP,*MAXHP,*STR,*INT,*ARM,weapon);
					break;
				case 'y':
				case 'Y':
					*CURRHP-=7;
					*ARM+=3;
					printf("You take the dagger and decisively slice open your palm. As the blood flows from "
					"within unto the altar,\na dark red mist surrounds you. You dealt 7 damage to yourself "
					"(HP: %d/%d). Armor increased by 3.\n",*CURRHP,*MAXHP);
					escape=true;
					break;
				case 'n':
				case 'N':
					printf("You refuse to take a blood oath with a demon, so you leave. After some wandering you find the road\n"
					"again, and you continue onwards.\n");
					escape=true;
					break;
				default:
					printf("Invalid Input. Please press y or n.\n");
					break;
			}
			if(escape)
				break;
		}
	}
	
	else if(strncmp(place,"Riddler",50)==0){
		printf("As you walk down the road, a tiny man dressed in green jumps out from a bush.\n"
		"\"Hold on there a second friend! I am Linus of the forest, and I will grant you\n"
		"one wish if you can answer my riddle!\"\nDo you stop to hear him out? [y/n]\n");
		
		while (1){
			scanf("%1c",&choice);
			while ( getchar() != '\n' );
			switch(choice){
				case 'i':
				case 'I':
					printf("You are a %s.\nHP: %d/%d\nSTR: %d\nINT: %d\nArmor: %d\nWeapon damage: %s\n",JOB,*CURRHP,*MAXHP,*STR,*INT,*ARM,weapon);
					break;
				case 'y':
				case 'Y':
					printf("\"Splendid! Splendid! Here is my riddle. I can fill a room without occupying any space.\n"
					"What am I? You have three tries.\" [Type the answer in lowercase]\n");
					for(i=0;i<3;i++){//three tries
						scanf("%s",&guess);
						while(getchar()!='\n');
						if (strncmp(guess,"air",50)==0 || strncmp(guess,"light",50)==0){
							printf("That's correct! ");
							guesscorrect=true;//if they pick correctly we flip this switch
							break;
						}
						else{
							printf("Nope!\n");
						}
					}
					if (guesscorrect){//if the switch is flipped we give them a reward
						printf("Congratulations, you have asnwered my riddle! What do you want in return?\n\n"
						"1.I want to be healthy.\n2.I want to be durable.\n3.I want to be ");
						if (strncmp(JOB,"Warrior",50)==0)
							printf("stronger.\n");
						else if (strncmp(JOB,"Mage",50)==0)
							printf("more intelligent.\n");
						printf("4.I want to be more deadly.\n");
						while(1){
						
							scanf("%d",&intchoice);
							while(getchar()!='\n');
							switch (intchoice){
								case 1:
									printf("MAX HP increases by 5.\n");
									*CURRHP+=5;
									*MAXHP+=5;
									escape_in_second_while=true;
									break;
								case 2:
									printf("Armor increases by 1.\n");
									*ARM+=1;
									escape_in_second_while=true;
									break;
								case 3:
									if(strncmp(JOB,"Warrior",50)==0){
										printf("Strength increases by 2.\n");
										*STR+=2;
									}
									else if(strncmp(JOB,"Mage",50)==0){
										printf("Intelligence increases by 2.\n");
										*INT+=2;
									}
									escape_in_second_while=true;
									break;
								case 4:
									if(strncmp(weapon,"d12",50)==0){
										printf("Unfortunately the weapon cannot be upgraded further. Pick another reward.\n");
										}
									else{
										printf("Weapon damage increases by 2.\n");
										if(strncmp(weapon,"d6",50)==0){
											sprintf(weapon,"d8");
										}
										else if(strncmp(weapon,"d8",50)==0){
											sprintf(weapon,"d10");
										}
										else if(strncmp(weapon,"d10",50)==0){
											sprintf(weapon,"d12");
										}
										escape_in_second_while=true;
									}
									break;
								default:
									printf("Invalid input. Please press 1,2, or 3.\n");
									break;
							
							}
						
						if(escape_in_second_while){
							break;
						}
						}
					printf("\n\"Thanks for playing with me!\" he exclaims and jumps back in the bush.\n");
					}
					else{
						printf("\"I am sorry, you did not guess correctly...\", he says, and jumps back in the bush.\n");
					}
						

					escape=true;
					break;
				case 'n':
				case 'N':
					printf("You have no time for weird people, so you ignore him. He walks away looking sad.\n");
					escape=true;
					break;
				default:
					printf("Invalid Input. Please press y or n.\n");
					break;
			}
			if(escape)
				break;
		}
	}
	else if(strncmp(place,"Bag",50)==0){
		printf("As you keep walking, you come across a duffle bag on the ground.\nInside there are various "
		"trinkets and baubles of no value, but among them, a vial holding a weird, sludgy, purple liquid.\n"
		"It looks gross. Do you want to drink it? [y/n]\n");
		
		while (1){
			scanf("%1c",&choice);
			while ( getchar() != '\n' );
			switch(choice){
				case 'i':
				case 'I':
					printf("You are a %s.\nHP: %d/%d\nSTR: %d\nINT: %d\nArmor: %d\nWeapon damage: %s\n",JOB,*CURRHP,*MAXHP,*STR,*INT,*ARM,weapon);
					break;
				case 'y':
				case 'Y':
					printf("You pray to your God and drink the entire thing in seconds. ");
					random=rand()%4;

					switch(random){
						case 0:
							*CURRHP-=10;
							printf("It burns your insides, inflicting\nunimaginable pain to your entire "
							"body. It deals 10 damage to you (HP: %d/%d). At least now\nyou know what "
							"it was.\n",*CURRHP,*MAXHP);
							break;
						case 1:
							if(strncmp(JOB,"Warrior",50)==0){
								*STR+=2;
								printf("It was a home-made Strength potion.\nTasted bitter. Strength increases by 2.\n");
							}
							else if(strncmp(JOB,"Mage",50)==0){
								*INT+=2;
								printf("It was a home-made Intelligence potion.\nTasted sweet! Intelligence increases by 2.\n");
							}
							break;
						case 2:
							printf("It was a potion of health.\nMAX HP increases by 5.\n");
							*CURRHP+=5;
							*MAXHP+=5;
							break;
						case 3:
							printf("You burp. Nothing happens.\n");
							break;
					}
					escape=true;
					break;
				case 'n':
				case 'N':
					printf("You do not want to risk drinking a random potion so you leave it behind.\n");
					escape=true;
					break;
				default:
					printf("Invalid Input. Please press y or n.\n");
					break;
			}
			if(escape)
				break;
		}
		
	}
	else if(strncmp(place,"Forest",50)==0){
		printf("The road passes through a forest unlike anything you've ever seen before.\n"
		"There are fireflies flying around, rays of sunlight escape the trees and illuminate the area, \n"
		"and you can swear you can hear an angelic voice chanting hymns. In the middle of the\nforest lies a lake. "
		"Waters clear as crystal, and as calm as can be. Do you wish to drink\nfrom the lake? [y/n]\n");
		
		while (1){
			scanf("%1c",&choice);
			while ( getchar() != '\n' );
			switch(choice){
				case 'i':
				case 'I':
					printf("You are a %s.\nHP: %d/%d\nSTR: %d\nINT: %d\nArmor: %d\nWeapon damage: %s\n",JOB,*CURRHP,*MAXHP,*STR,*INT,*ARM,weapon);
					break;
				case 'y':
				case 'Y':
					*MAXHP+=7;
					*CURRHP=*MAXHP;
					printf("You lie down and take a sip from the blessed waters. All your ailments are cured and\n"
					"your Maximum HP is increased by 7.\n");
					escape=true;
					break;
				case 'n':
				case 'N':
					printf("You do not trust this place, so you leave.\n");
					escape=true;
					break;
				default:
					printf("Invalid Input. Please press y or n.\n");
					break;
			}
			if(escape)
				break;
		}
	}
	else if(strncmp(place,"Village",50)==0){
		*CURRHP=*MAXHP;
		printf("Along the path you chose, you come upon a small village.\nThe villagers are very friendly "
		"and offer you a warm bowl of soup. HP restored to full (HP: %d/%d).\nThe village's blacksmith "
		"offers to upgrade either your armor or your weapon. Which do you choose? [a/w]\n",*CURRHP,*MAXHP);
		
		while (1){
			scanf("%1c",&choice);
			while ( getchar() != '\n' );
			switch(choice){
				case 'i':
				case 'I':
					printf("You are a %s.\nHP: %d/%d\nSTR: %d\nINT: %d\nArmor: %d\nWeapon damage: %s\n",JOB,*CURRHP,*MAXHP,*STR,*INT,*ARM,weapon);
					break;
				case 'a':
				case 'A':
					printf("Armor increases by 1.\n");
					*ARM+=1;
					escape=true;
					break;
				case 'w':
				case 'W':
					if(strncmp(weapon,"d12",50)==0){
						printf("Unfortunately the weapon cannot be upgraded further. ");
						printf("Armor increases by 1.\n");
						*ARM+=1;
					}
					else{
						printf("Weapon damage increases by 2.\n");
						if(strncmp(weapon,"d6",50)==0){
							sprintf(weapon,"d8");
						}
						else if(strncmp(weapon,"d8",50)==0){
							sprintf(weapon,"d10");
						}
						else if(strncmp(weapon,"d10",50)==0){
							sprintf(weapon,"d12");
						}
					}
					escape=true;	
					break;
				default:
					printf("Invalid Input. Please press a or w.\n");
					break;
			}
		if (escape)
			break;
		}
	}
}
int main(){
	
	//first we create a struct called character
	typedef struct {
		int STR;
		int INT;
		int max_hp;
		int curr_hp;
		int armor;
		char profession[7];
		char weapon[4];
	}character;
	
	char name[100];//name
	char choice;
	/*choice of left or right. the map consists of three crossroads, with the left and right road taking
	you to different places*/
	bool escape = false;//to exit while loops from switches
	int intmod, strmod, vilmod;//calculating damage
	int randdmg;//for how much damage is dealt

	time_t t;
	srand(time(&t));
	
	
	int i,random;//random is the variable that goes in the places thing (places[random])
	size_t spl;
	/*size of places array. Will lower every time i delete sth from it for my for loops*/

	
	//below are pointers to feed stuff in the encounter function
	
	character player;
	int * pointerSTR;
	int * pointerINT;
	int * pointermaxhp;
	int * pointercurrhp;
	int * pointerarmor;
	char * pointerjob;
	char * pointerweapon;
	
	pointerSTR=&player.STR;
	pointerINT=&player.INT;
	pointermaxhp=&player.max_hp;
	pointercurrhp=&player.curr_hp;
	pointerarmor=&player.armor;
	pointerweapon=player.weapon;
	pointerjob=player.profession; 

	character villain;

	//END OF VARIABLE DEFINITIONS

	// MAP INIT 
	
	char places[7][7]={"Castle","Anvil","Shrine","Riddler","Bag","Forest","Village"};

	char left1[7],right1[7],left2[7],right2[7],left3[7],right3[7];
	
	spl = (sizeof(places) / sizeof(places[0]));
	random = rand() % spl; //get a random number from 0 to the size of places
	sprintf(left1,places[random],7); //give left1 a random place
	for(i=random;i<spl;i++){ 
		sprintf(places[i],places[i+1],7); 
	}
	/*delete the place you got from the places array by shifting all places after the
	deleted place one step forwards.*/
	spl--; 
	//this is easier than using malloc and realloc, don't judge me
	random = rand() % spl; 
	sprintf(left2,places[random]); 
	for(i=random;i<spl;i++){ 
		sprintf(places[i],places[i+1]); 
	}
	spl--;
	
	random = rand() % spl; 
	sprintf(left3,places[random]); 
	for(i=random;i<spl;i++){ 
		sprintf(places[i],places[i+1]); 
	}
	spl--;
	
	random = rand() % spl; 
	sprintf(right1,places[random]); 
	for(i=random;i<spl;i++){ 
		sprintf(places[i],places[i+1]); 
	}
	spl--;
	
	random = rand() % spl; 
	sprintf(right2,places[random]); 
	for(i=random;i<spl;i++){ 
		sprintf(places[i],places[i+1]); 
	}
	spl--;
	
	random = rand() % spl; 
	sprintf(right3,places[random]); 
	for(i=random;i<spl;i++){ 
		sprintf(places[i],places[i+1]); 
	}
	spl--;
	
	// MAP INIT DONE
	
	//START OF GAME CODE
	
	printf("What is your name?\n");
	scanf("%99s",&name);
	while ( getchar() != '\n' );
	
	printf("Nice to meet you %s. Before we begin, do you want to be a mage or a warrior?[m/w]\n",name);
	while (1){
		scanf("%1c",&choice);
		while ( getchar() != '\n' );
		switch(choice){
			case 'm':
			case 'M':
				printf("Mage it is.\n");
				sprintf(player.profession,"Mage");
				player.STR=10;
				player.INT=20;
				player.max_hp=25;
				player.curr_hp=25;
				player.armor=3;
				sprintf(player.weapon,"d8");
				
				escape = true; //since i cannot break the while loop from a switch command i use a bool
				break;
			case 'w':
			case 'W':
				printf("Warrior it is.\n");
				sprintf(player.profession,"Warrior");
				player.STR=20;
				player.INT=10;
				player.max_hp=30;
				player.curr_hp=30;
				player.armor=5;
				sprintf(player.weapon,"d6");
				
				escape = true;
				break;
			default:
				printf("Invalid Input. Please press m or w.\n");
				//if we get wrong input we do not escape=true, so the while does not break
		}
		if (escape){
			break;
		}
	}

	escape=false; //reset the escape bool so it will stop the player on the next branch

	printf("You are %s, an adventurer mercenary %s. One day after you visited your favourite tavern,\n"
	"you are approached by an old stranger in robes. They explain that they are a wizard who got \n"
	"one of their artifacts stolen by one of their enemies. They task you with retrieving the \n"
	"artifact after they tell you the location of the villains tower, and you begin your journey.\n\n",name,player.profession);

	printf("**Note: you can press 'i' in every input screen to inspect your character**\n\n");
	
	printf("On the road to the tower, the path branches left and right. Where do you wish to go?[l/r]\n");

	while (1){
		scanf("%1c",&choice);
		while ( getchar() != '\n' );
		switch(choice){
			case 'i':
			case 'I':
				printf("You are a %s.\nHP: %d/%d\nSTR: %d\nINT: %d\nArmor: %d\nWeapon damage: %s\n",player.profession,player.curr_hp,player.max_hp,player.STR,player.INT,player.armor,player.weapon);
				break;
			case 'l':
			case 'L':
				printf("You chose to follow the left path. ");
				encounter(left1,pointerSTR,pointerINT,pointermaxhp,pointercurrhp,pointerjob,pointerarmor,pointerweapon);
				//it encounters the place that we put on left1 size of the map, and feeds all the player data as well
				escape=true;
				break;
			case 'r':
			case 'R':
				printf("You chose to follow the right path. ");
				encounter(right1,pointerSTR,pointerINT,pointermaxhp,pointercurrhp,pointerjob,pointerarmor,pointerweapon);
				escape=true;	
				break;
			default:
				printf("Invalid Input. Please press r or l.\n");
				break;
		}
		if (escape)
			break;
	}
	escape=false;
	printf("You press on, and after a while, the path yet again branches left and right. Where do you wish to go?[l/r]\n");

	while (1){
		scanf("%1c",&choice);
		while ( getchar() != '\n' );
		switch(choice){
			case 'i':
			case 'I':
				printf("You are a %s.\nHP: %d/%d\nSTR: %d\nINT: %d\nArmor: %d\nWeapon damage: %s\n",player.profession,player.curr_hp,player.max_hp,player.STR,player.INT,player.armor,player.weapon);
				break;
			case 'l':
			case 'L':
				printf("You chose to follow the left path. ");
				encounter(left2,pointerSTR,pointerINT,pointermaxhp,pointercurrhp,pointerjob,pointerarmor,pointerweapon);

				escape=true;
				break;
			case 'r':
			case 'R':
				printf("You chose to follow the right path. ");
				encounter(right2,pointerSTR,pointerINT,pointermaxhp,pointercurrhp,pointerjob,pointerarmor,pointerweapon);
				escape=true;	
				break;
			default:
				printf("Invalid Input. Please press r or l.\n");
				break;
		}
		if (escape)
			break;
	}
	escape=false;
	printf("As you continue down the path, you see a final branching path ahead of you. Where do you wish to go?[l/r]\n");

	while (1){
		scanf("%1c",&choice);
		while ( getchar() != '\n' );
		switch(choice){
			case 'i':
			case 'I':
				printf("You are a %s.\nHP: %d/%d\nSTR: %d\nINT: %d\nArmor: %d\nWeapon damage: %s\n",player.profession,player.curr_hp,player.max_hp,player.STR,player.INT,player.armor,player.weapon);

				break;
			case 'l':
			case 'L':
				printf("You chose to follow the left path. ");
				encounter(left3,pointerSTR,pointerINT,pointermaxhp,pointercurrhp,pointerjob,pointerarmor,pointerweapon);

				escape=true;
				break;
			case 'r':
			case 'R':
				printf("You chose to follow the right path. ");
				encounter(right3,pointerSTR,pointerINT,pointermaxhp,pointercurrhp,pointerjob,pointerarmor,pointerweapon);
				escape=true;	
				break;
			default:
				printf("Invalid Input. Please press r or l.\n");
				break;
		}
		if (escape)
			break;
	}	
	
	escape=false;
				
	//final boss
	
	printf("After a long journey, you finally reach the tower the villainous wizard resides. You enter through the front\n"
	"door and confront him\n");
	printf("\"Ah. %s. I foresaw this encounter. You should know I have no intention of just handing this precious\n"
	"crystal to you, after all the trouble I went through to acquire it. If you want it, you will have to kill me.\"\n\n",name);
	printf("Your Stats:\nHP: %d/%d\nSTR: %d\nINT: %d\nArmor: %d\nWeapon damage: %s\n",player.curr_hp,player.max_hp,player.STR,player.INT,player.armor,player.weapon);

	printf("\nPress any button to continue\n");
	getch();
	
	villain.INT=22;
	villain.max_hp=28;
	villain.curr_hp=28;
	villain.armor=4;
	
	//this is for damage calculation, the more str or int the player has, the more damage they deal
	strmod=(player.STR-10)/2;
	intmod=(player.INT-10)/2;
	vilmod=(villain.INT-10)/2;
	
	//Fight
	
	while(player.curr_hp>0 && villain.curr_hp>0){
		randdmg=rand() % 8+1 + vilmod-player.armor;
		//damage is d8 + the villains intelligence modifier - the player armor
		if (randdmg<0)
			randdmg=0;//if the damage is negative it would heal the player so we set it to 0
		player.curr_hp-=randdmg;//subtract it from the health
		printf("The villain attacks for %d damage! Player HP: %d/%d\n",randdmg,player.curr_hp,player.max_hp);
		//print the result of the calculation
		sleep(3);//give some time for the player to read and for suspense
		if(player.curr_hp<=0)
			break;//if the player dies we break early 
		if(strncmp(player.profession,"Warrior",50)==0){//if they are a warrior we use strength mod for damage
			if(strncmp(player.weapon,"d6",50)==0){//depending on the weapon, we calculate the damage
				randdmg=rand() % 6+1 + strmod - villain.armor;
				if (randdmg<0)
					randdmg=0;
				villain.curr_hp-=randdmg;
				printf("You attack for %d damage! Villain HP: %d/%d\n",randdmg,villain.curr_hp,villain.max_hp);
				sleep(3);
			}
			else if(strncmp(player.weapon,"d8",50)==0){
				randdmg=rand() % 8+1 + strmod - villain.armor;
				villain.curr_hp-=randdmg;
				if (randdmg<0)
					randdmg=0;
				printf("You attack for %d damage! Villain HP: %d/%d\n",randdmg,villain.curr_hp,villain.max_hp);
				sleep(3);
			}
			else if(strncmp(player.weapon,"d10",50)==0){
				randdmg=rand() % 10+1 + strmod - villain.armor;
				if (randdmg<0)
					randdmg=0;
				villain.curr_hp-=randdmg;
				printf("You attack for %d damage! Villain HP: %d/%d\n",randdmg,villain.curr_hp,villain.max_hp);
				sleep(3);
			}
			else if(strncmp(player.weapon,"d12",50)==0){
				randdmg=rand() % 12+1 + strmod - villain.armor;
				if (randdmg<0)
					randdmg=0;				
				villain.curr_hp-=randdmg;
				printf("You attack for %d damage! Villain HP: %d/%d\n",randdmg,villain.curr_hp,villain.max_hp);
				sleep(3);
			}
		}
		else if(strncmp(player.profession,"Mage",50)==0){//if it is a mage we use intelligence mod
			if(strncmp(player.weapon,"d6",50)==0){
				randdmg=rand() % 6+1 + intmod - villain.armor;
				if (randdmg<0)
					randdmg=0;
				villain.curr_hp-=randdmg;
				printf("You attack for %d damage! Villain HP: %d/%d\n",randdmg,villain.curr_hp,villain.max_hp);
				sleep(3);
			}
			else if(strncmp(player.weapon,"d8",50)==0){
				randdmg=rand() % 8+1 + intmod - villain.armor;
				if (randdmg<0)
					randdmg=0;
				villain.curr_hp-=randdmg;
				printf("You attack for %d damage! Villain HP: %d/%d\n",randdmg,villain.curr_hp,villain.max_hp);
				sleep(3);
			}
			else if(strncmp(player.weapon,"d10",50)==0){
				randdmg=rand() % 10+1 + intmod - villain.armor;
				if (randdmg<0)
					randdmg=0;
				villain.curr_hp-=randdmg;
				printf("You attack for %d damage! Villain HP: %d/%d\n",randdmg,villain.curr_hp,villain.max_hp);
				sleep(3);
			}
			else if(strncmp(player.weapon,"d12",50)==0){
				randdmg=rand() % 12+1 + intmod - villain.armor;
				if (randdmg<0)
					randdmg=0;
				villain.curr_hp-=randdmg;
				printf("You attack for %d damage! Villain HP: %d/%d\n",randdmg,villain.curr_hp,villain.max_hp);
				sleep(3);
			}
		}
	}
	
	if(player.curr_hp<=0){
		printf("\n\nYour story ends abruptly. Your body fed to the vultures. Forgotten. Alone.\n\n");
	}
	if (villain.curr_hp<=0){
		printf("\n\nYou return home victorious, present the crystal to its rightful owner, and you are showered\n"
		"in riches for it. Congratulations.");
	}

}
