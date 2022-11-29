#!/bin/python
import subprocess
import sys
import os

def parse_args():
    b = o = r = None
    for i, arg in enumerate(sys.argv):
        if arg in ['-b', '--branch']:
            try: 
                b = sys.argv[i+1]
                continue
            except: pass
        if arg in ['-o', '--output']:
            try:
                o = sys.argv[i+1]
                continue
            except: pass
        if arg in ['-p', '--path']:
            try:
                r = sys.argv[i+1]
                continue
            except: pass
    return (b, o, r)


def main():
    if len(sys.argv) <= 1: return
    url = sys.argv[1]
    branch, outdir, rpath = parse_args()
    if outdir is None:
        outdir = subprocess.run(['basename', url, '.git'], encoding='utf-8', stdout=subprocess.PIPE).stdout.strip()
    # print(f"url is {url}, b is {branch}, o is {outdir} p is {rpath}")
    
    cmd = "git clone --depth 1 --filter=tree:0 --no-checkout"
    if branch: cmd += " --branch " + branch
    cmd += " " + url + " " + outdir
    subprocess.run(cmd.split(' '))
    
    # print(outdir, branch, rpath)
    
    os.chdir(outdir)
    subprocess.run(['git', 'sparse-checkout', 'set', rpath])
    if branch: subprocess.run(['git', 'checkout', branch])
    else: subprocess.run(['git', 'checkout'])

if __name__ == "__main__":
    main()
