# C++ Project: Option pricing with Black-Scholes and Binomial models.

## Authors
- Théo MORET
- Jérôme ALLIER
- Bastien CANNARD

## Task Distribution
- **Théo**: Development and Implementation of the Black-Scholes model for price trajectory simulation via Monte Carlo. Backtesting of models using online pricers.
- **Jérôme**: Development and Implementation of the differents options. Documentation writing.
- **Bastien**: Development of the discrete-time binomial model for American and European options. Documentation writing and README.md creating.

## The Utility of C++ in the Project
This C++ project aimed at determining the pricing of financial
options with two different models : Black-Scholes model thanks to Monte Carlo simulations and Binomial model. 

Firstly, C++ is renowned for its high performance in terms of execution 
speed, which is crucial in the field of quantitative finance where 
rapid data processing and computations are essential. 
C++'s ability to handle complex and computationally intensive operations,
such as those required in Monte Carlo methods for simulating asset price trajectories, gives it a significant advantage over other, slower programming languages.  

Moreover, C++ offers low-level control over memory management, 
allowing for fine-tuning of the code for enhanced performance,
This feature enables more efficient execution of Monte Carlo simulations,
thereby reducing the time needed to obtain accurate results 
for option pricing and replication strategies.  

The object-oriented programming (OOP) of C++ is also a major advantage, 
allowing for an intuitive modeling of complex financial entities 
such as options and models. OOP facilitates the organization of code,
making the program's development and maintenance simpler 
and more efficient. 
This allows for the creation of extensible and reusable structures,
ideal for adapting and extending the Black-Scholes model 
to different market conditions or types of options.  

Additionally, the wealth of libraries and tools available for C++ 
is a significant asset. 
There are numerous powerful libraries for mathematical operations, 
random number generation, and statistical computations, 
all essential in implementing the Monte Carlo method and financial modeling in general.  

Lastly, C++ is widely used in the financial industry, 
which means that developing skills in this language 
and familiarizing oneself can be directly applicable 
and beneficial in a professional context. 
This makes the project not only academically enriching but also professionally relevant.


## Ease of Use, Scalability, and Reusability.

The design and structure of our code make it user-friendly, 
scalable, and reusable, particularly suited for various scenarios 
beyond its current application in pricing financial options 
and implementing replication strategies in the Black-Scholes-Merton model. 

First and foremost, the clear separation of concerns achieved 
by using separate .h and .cpp files for options, 
the binomial model, the Black-Scholes model, 
and the Monte Carlo method enhances readability and maintainability. 
Each component is encapsulated in its module, 
allowing for easier understanding, debugging, and modification without affecting other parts of the system.  

The use of OOP principles 
further contributes to this modular approach. 
By defining distinct classes for different financial models and options,
our code becomes inherently scalable. 
New models or option types can be added with minimal adjustments 
to the existing codebase. This extensibility is important for adapting to new financial instruments or market conditions.  

 Moreover, the reusability aspect is reinforced by abstracting 
 common functionalities into reusable classes and functions. 
 This means that the same code base can be applied to a wide range 
 of financial products and scenarios, not just limited to 
 the specific cases we've initially targeted. 
 For instance, the Monte Carlo simulation module can be easily 
 adapted or extended for different stochastic processes 
 beyond its current use.

The intuitive structure 
of the main simulation file 
(main.cpp) enables users to easily simulate different scenarios. 
By altering input parameters or financial products, 
users can leverage our comprehensive suite of models 
to analyze a broad spectrum of options under varying conditions. 

Finally, the code is well-commented and documented to ensure easy comprehension by new users.

## Coverage of a Wide Range of Options
Our suite of models covers a wide range of financial options:

- **European Options**: Priced using the Black-Scholes model for instance.
- **American Options**: Evaluated using the binomial model for example.
- **Price Simulations**: Monte Carlo model used for simulating price trajectories under various market scenarios.

## Class Diagrams
Class diagrams illustrating the architecture and relationships 
between different components of the system are included in the folder.

## Backtesting the Model
We backtested our models by comparing the prices of European and American options.
The results show a close match with online pricers, validating the accuracy of our models.


## Code Demonstration
We plan a live demonstration of the code during the defense scheduled for 01/12. This demo will include:

- Presentation of the Code and Explanation of Its Operation (10 minutes).
- Question and Answer Session (5 minutes).
