#!/usr/bin/env python3

import sys


def score_analytics():
    print("=== Player Score Analytics ===")
    total_players = len(sys.argv) - 1
    if total_players >= 1:
        scores = []
        for score in sys.argv[1:]:
            try:
                points = int(score)
                scores.append(points)
            except ValueError:
                print(f"Invalid parameter '{score}'")
        if not scores:
            print("No scores provided. Usage: python3", end="")
            print(" ft_score_analytics.py <score1> <score2> ...")
            return
        print(f"Scores processed: {scores}")
        total_scores = sum(scores)
        average = total_scores / len(scores)
        high_score = max(scores)
        low_score = min(scores)
        score_range = high_score - low_score
        print(f"Total players: {len(scores)}")
        print(f"Total score: {total_scores}")
        print(f"Average score: {average}")
        print(f"High score: {high_score}")
        print(f"Low score: {low_score}")
        print(f"Score range: {score_range}")
    else:
        print("No scores provided. Usage: python3", end="")
        print(" ft_score_analytics.py <score1> <score2> ...")


if __name__ == "__main__":
    score_analytics()
