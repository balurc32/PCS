%% esercitazione 4 PCS

clc
clear

dim = [4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192];

t_bubble = [7.5e-07, 9.17e-07, 3.542e-06, 1.2833e-05, 3.6292e-05, 0.000136667, 0.000638375, 0.00213788, 0.00669025, 0.020111, 0.0549899, 0.215611];
t_insertion = [6.67e-07, 3.75e-07, 1.916e-06, 5e-06, 1.5208e-05, 5.9042e-05, 0.000233125, 0.00089475, 0.00253454, 0.00675546, 0.0195606, 0.0782784];
t_selection = [5e-07, 9.17e-07, 2.917e-06, 7.833e-06, 2.3e-05, 0.000102834, 0.00041525, 0.000875458, 0.00280271, 0.00665183, 0.0203598, 0.0796053];
t_std = [1.291e-06, 9.17e-07, 2.333e-06, 6.459e-06, 1.2708e-05, 3.0833e-05, 6.6167e-05, 0.000117125, 0.000218292,0.000320917, 0.000579166, 0.00119408];


figure;
loglog(dim, t_bubble, '-o', 'LineWidth', 1.5); hold on;
loglog(dim, t_insertion, '-s', 'LineWidth', 1.5);
loglog(dim, t_selection, '-^', 'LineWidth', 1.5);
loglog(dim, t_std, '-d', 'LineWidth', 1.5);

xlabel('dim');
ylabel('tempo (s)');
legend('bubblesort', 'insertionsort', 'selectionsort', 'sort library', 'Location', 'northwest');
title('Confronto algoritmi di ordinamento');