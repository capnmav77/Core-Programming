class Engine 
{
	public:
    	void start() 
	{
        	// Code to start the engine
    	}
};

class Car 
{
	public:
    	Car()
	{
		engine = new Engine();
	}
    	
    	void startCar() 
	{
        	engine->start();
    	}
	private:
    	Engine* engine;
};

int main() 
{
    Car car;
    car.startCar();
    return 0;
}