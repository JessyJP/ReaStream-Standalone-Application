clc;clear;
% Define variables
syms  dt dc dx
% Variable vector
vars = [dt dc dx];


% Inputs #1
% syms  A1 B1 B2 A2
% vars = [vars, A1 B1 B2 A2];


% Inputs #2
A1 = 0 ;
B1 = 10;
B2 = 12;
A2 = 16;

eqn(1) = A2 - A1 == 2*dt + dc;
eqn(2) = B2 - B1 == dc;
eqn(3) = B1 - A1 == dt   + dx;
eqn(4) = A2 - B2 == dt   - dx;


% #1
% eqn(end+1) = A1 == 0;
% eqn(end+1) = B1 == 12;
% eqn(end+1) = B2 == B1;
% eqn(end+1) = A2 == 10;



[M,v] = equationsToMatrix(eqn, vars);

rank(M)

X = linsolve(M,v)