import matplotlib.pyplot as plt
import numpy as np
import random
import statistics
import argparse

def parse_args():
    parser = argparse.ArgumentParser(description='Simulador de ruleta')
    parser.add_argument('-c', type=int, default=1,   help='Cantidad de corridas')
    parser.add_argument('-n', type=int, default=100, help='Tiradas por corrida')
    parser.add_argument('-e', type=int, default=7,   help='Número elegido (0-36)')
    return parser.parse_args()

red = [1,3,5,7,9,12,14,16,18,19,21,23,25,27,30,32,34,36]

def tirar():
    return random.randint(0, 36)

def fr(xi, n):
    return round(xi / n, 4)

# ── Gráfico de línea (convergencia) ─────────────────────────────────────────
def plot_linea(ax, ns, y_sim, y_esp, ylabel, label_sim, label_esp):
    ax.plot(list(ns), y_sim, color='red', linewidth=1.2, label=label_sim)
    ax.axhline(y_esp, color='blue', linewidth=2, label=label_esp)
    ax.set_xlabel('n (número de tiradas)')
    ax.set_ylabel(ylabel)
    ax.legend(fontsize=8)

# ── Gráfico de barras con valor esperado ─────────────────────────────────────
def plot_barras(ax, categorias, valores, valores_esp, ylabel, titulo):
    ax.bar(categorias, valores, color='red', alpha=0.7, label='Simulado')
    for i, esp in enumerate(valores_esp):
        ax.hlines(esp, i - 0.4, i + 0.4, colors='blue', linewidth=2,
                  label='Esperado' if i == 0 else '')
    ax.set_ylabel(ylabel)
    ax.set_title(titulo)
    ax.legend(fontsize=8)

# ── Figura 1: convergencia ───────────────────────────────────────────────────
def graficar_convergencia(corrida, numero_elegido, idx_corrida):
    N  = len(corrida)
    ns = range(1, N + 1)

    fre = 1 / 37
    vpe = sum(range(37)) / 37
    vve = np.var(range(37))
    vde = np.std(range(37))

    frn, vpn, vvn, vdn = [], [], [], []
    for i in range(N):
        sub = corrida[:i + 1]
        frn.append(sub.count(numero_elegido) / (i + 1))
        vpn.append(np.mean(sub))
        vvn.append(np.var(sub) if i > 0 else 0)
        vdn.append(np.std(sub) if i > 0 else 0)

    fig, axes = plt.subplots(2, 2, figsize=(13, 8))
    fig.suptitle(f'Corrida {idx_corrida} — convergencia (número elegido: {numero_elegido})', fontsize=13)

    plot_linea(axes[0,0], ns, frn, fre, 'fr (frecuencia relativa)',
               'frn (simulada)', f'fre = {fre:.4f} (esperada)')
    plot_linea(axes[0,1], ns, vpn, vpe, 'vp (valor promedio)',
               'vpn (simulado)', f'vpe = {vpe:.2f} (esperado)')
    plot_linea(axes[1,0], ns, vdn, vde, 'vd (desvío estándar)',
               'vdn (simulado)', f'vde = {vde:.4f} (esperado)')
    plot_linea(axes[1,1], ns, vvn, vve, 'vv (varianza)',
               'vvn (simulada)', f'vve = {vve:.4f} (esperada)')

    plt.tight_layout()
    plt.show()

# ── Figura 2: distribuciones ─────────────────────────────────────────────────
def graficar_distribuciones(corrida, idx_corrida):
    N = len(corrida)

    redTh   = sum(1 for t in corrida if t in red)
    blackTh = sum(1 for t in corrida if t not in red and t != 0)
    greenTh = N - redTh - blackTh
    par     = sum(1 for t in corrida if t > 0 and t % 2 == 0)
    impar   = N - par - greenTh
    p1      = sum(1 for t in corrida if 1  <= t <= 12)
    p2      = sum(1 for t in corrida if 13 <= t <= 24)
    p3      = sum(1 for t in corrida if 25 <= t <= 36)

    fig, axes = plt.subplots(2, 2, figsize=(13, 8))
    fig.suptitle(f'Corrida {idx_corrida} — distribuciones', fontsize=13)

    # 1) Colores
    plot_barras(
        axes[0,0],
        ['Roja', 'Negra', 'Verde'],
        [fr(redTh, N), fr(blackTh, N), fr(greenTh, N)],
        [18/37, 18/37, 1/37],
        'Frecuencia relativa', 'Distribución por color'
    )

    # 2) Par / Impar
    plot_barras(
        axes[0,1],
        ['Par', 'Impar'],
        [fr(par, N), fr(impar, N)],
        [18/37, 18/37],
        'Frecuencia relativa', 'Par / Impar'
    )

    # 3) Piernas (tercios)
    plot_barras(
        axes[1,0],
        ['1ª (1–12)', '2ª (13–24)', '3ª (25–36)'],
        [fr(p1, N), fr(p2, N), fr(p3, N)],
        [12/37, 12/37, 12/37],
        'Frecuencia relativa', 'Distribución por pierna'
    )

    # 4) Frecuencia de cada número ordenada de mayor a menor
    conteos  = {n: corrida.count(n) for n in range(37)}
    ordenado = sorted(conteos.items(), key=lambda x: x[1], reverse=True)
    nums, freqs = zip(*ordenado)
    axes[1,1].bar([str(n) for n in nums], [f/N for f in freqs], color='red', alpha=0.7)
    axes[1,1].axhline(1/37, color='blue', linewidth=2, label=f'Esperado = {1/37:.4f}')
    axes[1,1].set_xlabel('Número')
    axes[1,1].set_ylabel('Frecuencia relativa')
    axes[1,1].set_title('Números ordenados por frecuencia')
    axes[1,1].tick_params(axis='x', labelsize=6, rotation=90)
    axes[1,1].legend(fontsize=8)

    plt.tight_layout()
    plt.show()

# ── Main ─────────────────────────────────────────────────────────────────────
def main():
    args = parse_args()
    corridas          = args.c
    tiradasPorCorrida = args.n
    elegido           = args.e

    print(f"Simulador de ruleta | corridas={corridas} | tiradas={tiradasPorCorrida} | número={elegido}\n")

    matCorridas = [
        [tirar() for _ in range(tiradasPorCorrida)]
        for _ in range(corridas)
    ]

    for i, corrida in enumerate(matCorridas, start=1):
        redTh   = sum(1 for t in corrida if t in red)
        blackTh = sum(1 for t in corrida if t not in red and t != 0)
        greenTh = tiradasPorCorrida - redTh - blackTh
        par     = sum(1 for t in corrida if t > 0 and t % 2 == 0)
        impar   = tiradasPorCorrida - par - greenTh

        print(f"─── Corrida {i} ───")
        print(f"  Rojas:   abs={redTh:>3}  rel={fr(redTh,   tiradasPorCorrida)}")
        print(f"  Negras:  abs={blackTh:>3}  rel={fr(blackTh, tiradasPorCorrida)}")
        print(f"  Verdes:  abs={greenTh:>3}  rel={fr(greenTh, tiradasPorCorrida)}")
        print(f"  Pares:   abs={par:>3}  rel={fr(par,     tiradasPorCorrida)}")
        print(f"  Impares: abs={impar:>3}  rel={fr(impar,   tiradasPorCorrida)}")
        modas = statistics.multimode(corrida)
        label = 'Número más caliente' if len(modas) == 1 else 'Números más calientes'
        print(f"  {label}: {sorted(modas)}\n")

        graficar_convergencia(corrida, elegido, i)
        graficar_distribuciones(corrida, i)

if __name__ == '__main__':
    main()