#include "veb.h"
#include "queue.h"
#include "dict.h"

int main(){

	vEB *v = NULL;
	int choice;
	int c,i,m;
	int u = 16;
	queue q = NULL;
	char* ip;
	int cc_;
	vEB *s = NULL;
	
	
	for(i = 0;i<u ;i++){
		v = insert(v,i,1,u);
	}
	int count,index;
	do{
		printf("\n1.Find Destination \n2.Change RT\n3.Exit");
		scanf("%d",&c);
		switch(c){
			case 1:
				while(1){
					printf("\nEnter Header");
					scanf("%ms",&ip);
					cc_ = mapping(ip[0]);
					enqueue(&q,cc_);
					printf("\nWant to insert more? 1 to insert 0 to exit...");
					scanf("%d",&m);
					if(m == 0)
						break;
				}
				while(q){
					cc_ = dequeue(&q);
					s = vEB_tree_member(v,cc_ );
					if(s)
						printf("\nPacket Accepted and will be forwarded to its destination");
					else
						printf("\nPacket Rejected");
				}
				break;
			case 2:

	do{
		printf("1.Insert\n2.Delete\n3.Traverse\n4.Exit");
		scanf("%d",&choice);
		switch(choice){

			case 1:
				printf("Enter IP and count");
				scanf("%d%d",&index,&count);
				v = insert(v,index,count,u);
				break;
			case 2:
				printf("Enter the IP to remove");
				scanf("%d",&index);
				v = removeip(v,index,u);
				break;
			case 3:
				for(i = 0;i<u;i++){
				printf("%d ip of %d\n", vEB_tree_elements(v, i),i);	
				}

			default:
				if(choice != 4)
					printf("\nEnter the valid choice");
				break;
		}
	}while(choice != 4);
	break;
			default:
	if(c != 3)
	printf("\nInvalid choice");
	break;


		}
	}while(c != 3);
}

