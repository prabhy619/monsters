#ifndef DMAP_H
#define DMAP_H
#include<vector>
#include<cstdlib>
#include<ctime>

int randgen(int lower,int higher)
{
//	srand(time(NULL));
	int a=rand();
	int b=a%(higher-lower+1);
	return b+lower;
}

int abs(int a)
{
	if(a>=0)
	{
		return a;
	}
	return -a;

}
class point
{
	public:
		int x;
		int y;
		point(int X,int Y)
		{
			x=X;
			y=Y;
		}
};
class rectangle
	{
		//https://help.adobe.com/en_US/FlashPlatform/reference/actionscript/3/flash/geom/rectangle.html
		public:
		int x;
		int y;
		int width;
		int height;
		rectangle(int a,int b,int c , int d)
		{
			x=a;
			y=b;
			width=c;
			height=d;
		}
		int top()
		{
			return (y+height);
		}
		int right()
		{
			return(x+width);
		}
		int bottom()
		{
			return(y);
		}
		int left()
		{
			return(x);
		}
	};

class leaf
{
	private:
		const int min_size=4;
	public:
		int x;
		int y;
		int width;
		int height;
		leaf* leftc;
		leaf* rightc;
		rectangle* room;
		std::vector< rectangle> hall;

		leaf(int X,int Y,int WIDTH,int HEIGHT)
		{
			x=X;
			y=Y;
			width=WIDTH;
			height=HEIGHT;
		}

		bool split()	//
		{
			srand(time(NULL));
			if(leftc!=NULL || rightc!= NULL)
				{return false;}
			bool splitH=randgen(0,100)>50;

			if (width > height && width / height >= 1.25)
				splitH = false;
			else if (height > width && height / width >= 1.25)
				splitH = true;

			int max=(splitH?height:width)-min_size;
			if(max<=min_size)
				return false;
			int split=randgen(min_size,max);//determine where we are splitting
			//Create left and right children based on direction of split,(splith==split height)
			if(splitH)
			{
				leftc=new leaf(x,y,width,split);//OMEGA
				rightc=new leaf(x,y+split,width,height-split);//SHIIELD
			}
			else
			{
				leftc=new leaf(x,y,split,width);//DRAWN
				rightc=new leaf(x+split,y,width-split,height);//YADA YADA
			}
			return true;	//split successful
		}
		void createleaf()
		{
			srand(time(NULL));
			int MAX_LEAF_SIZE=20;
			std::vector<leaf*> _leaf;
			//leaf* l;//helper leaf
			leaf* root=new leaf(0,0,1280,720);//DELETE THIS LATER
			_leaf.push_back(root);
			bool did_split=true;
			while (did_split)
			{
				did_split=false;
				for(leaf* l:_leaf )//edit this
				{
					if(l->leftc==NULL && l->rightc==NULL)
					{
						if(l->width>MAX_LEAF_SIZE  ||l->height>MAX_LEAF_SIZE || randgen(0,100)>25)
						{	
							if(l->split())
							{
								//if we split ,push_back child leaf to vector so we ccan loop them next
								_leaf.push_back(l->leftc);
								_leaf.push_back(l->rightc);
								did_split=true;
							}
						;}
					;}
				;}
			}
			root->createRooms();
			//LORUM IPSEM YADA YADA
		};
		void createRooms()
		{
			if(leftc!=NULL || rightc!=NULL)
			{
				if(leftc!=NULL)
				{
					leftc->createRooms();
				}
				if(rightc!=NULL)
				{
					rightc->createRooms();
				}
				if(leftc!= NULL && rightc!=NULL)
				{
					createHall(leftc->getRoom(),rightc->getRoom());
				}
			}
			else 
			{
				//leftc is NULL and since the createleaf divided it as
				//much as it could therefore it wont be divided into rooms
				//point* roomSize=new point(randgen(3, width - 2), randgen(3, height - 2));
				point* roomSize=new point(randgen(3, width - 2), randgen(3, height - 2));
				point* roomPos =new point(randgen(1, width - roomSize->x - 1), randgen(1, height - roomSize->y - 1));
				room = new rectangle(x+roomPos->x,y+roomPos->y,roomSize->x,roomSize->y);
				//this can produce intersecting rooms
			}
		}	
		rectangle* getRoom()
		{
			srand(time(NULL));
			//iterate through a room to find a room if it exists
			if(room!=NULL)
				return room;
			else
			{
				rectangle* lroom;
				rectangle* rroom;
				if(leftc!=NULL)
				{
					lroom=leftc->getRoom();
				}
				if(rightc!=NULL)
				{
					rroom=rightc->getRoom();
				}
				if(lroom==NULL and rroom==NULL)
					return NULL;
				else if(rroom==NULL)
					return lroom;
				else if(lroom==NULL)
					return rroom;
				else if(randgen(0,100)>50)
					return lroom;
				else 
					return rroom;
			}
		}
		void createHall(rectangle *L,rectangle *R)
		{
			srand(time(NULL));
			//Select two points in the room, connect those 
			std::vector<rectangle*> halls;		
		point point1(randgen(L->left() + 1, L->right() - 2), randgen(L->top() + 1, L->bottom() - 2));
		point point2(randgen(R->left() + 1, R->right() - 2), randgen(R->top() + 1, R->bottom() - 2));
			int w=point2.x-point1.x;
			int h=point2.y-point1.y;
			if(w<0)
			{
				if(h<0)
				{
					if(randgen(0,100)<50)
					{
						halls.push_back(new rectangle(point2.x, point1.y, abs(w), 1));
					}
					else
					{
						halls.push_back(new rectangle(point2.x, point2.y, abs(w), 1));
						halls.push_back(new rectangle(point1.x, point2.y, 1, abs(h)));
					}
				}
				else if(h>0)
				{
					if(randgen(0,100)<50)
					{
						halls.push_back(new rectangle(point2.x, point1.y, abs(w), 1));
						halls.push_back(new rectangle(point2.x, point1.y, 1, abs(h)));
					}
					else
					{
						halls.push_back(new rectangle(point2.x, point2.y, abs(w), 1));
						halls.push_back(new rectangle(point1.x, point1.y, 1, abs(h)));
					}
				}
				else
				{
					halls.push_back(new rectangle(point2.x, point2.y, abs(w), 1));
				}
			}
			else if (w > 0)
			{
				if (h < 0)
				{
					if (randgen(0,100) < 50)
					{
						halls.push_back(new rectangle(point1.x, point2.y, abs(w), 1));
						halls.push_back(new rectangle(point1.x, point2.y, 1, abs(h)));
					}
					else
					{
						halls.push_back(new rectangle(point1.x, point1.y, abs(w), 1));
						halls.push_back(new rectangle(point2.x, point2.y, 1, abs(h)));
					}
				}
				else if (h > 0)
				{
					if (randgen(0,100) < 50)
					{ 
						halls.push_back(new rectangle(point1.x, point1.y, abs(w), 1));
             					halls.push_back(new rectangle(point2.x, point1.y, 1, abs(h)));
            				}
            				else
            			{
                				halls.push_back(new rectangle(point1.x, point2.y, abs(w), 1));
                				halls.push_back(new rectangle(point1.x, point1.y, 1, abs(h)));
            				}
        			}	
        			else // if (h == 0)
        			{
            				halls.push_back(new rectangle(point1.x, point1.y, abs(w), 1));
        			}
				}
			else
			{
				if(h<0)
				{
					halls.push_back(new rectangle(point2.x,point2.y,1,abs(h)));
				}
				else if(h>0)
				{
					halls.push_back(new rectangle(point1.x,point1.y,1,abs(h)));
				}
    			}
		}

};
#endif
