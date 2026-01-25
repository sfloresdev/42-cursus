#!/usr/bin/env python3
"""
module03.ex1.ft_score_analytics - Procesador de puntuaciones

Ahora que dominamos la comunicación por comandos, esta es la primera misión
'PixelMetrics3000' necesita un 'Score Cruncher'. Un scoreboard basicamente...
Pero aqui, construimos el motor que la impulsa
"""
import sys


def score_analytics():
    print("=== Player Score Analytics ===")
    total_players = len(sys.argv) - 1
    if total_players > 1:
        total_score = 0
        range = 0
        for score in sys.argv[1:]:
            total_score = sum(score)
        average = total_players / total_players
        high_score = max()
        min_score  = min() 
        

            
