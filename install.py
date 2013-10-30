#! /usr/bin/env python
import os
import subprocess
import shutil

try:
    import argparse as ap
except ImportError:
    import pyne._argparse as ap

absexpanduser = lambda x: os.path.abspath(os.path.expanduser(x))

def check_windows_cmake(cmake_cmd):
    if os.name == 'nt':
        files_on_path = set()
        for p in os.environ['PATH'].split(';')[::-1]:
            if os.path.exists(p):
                files_on_path.update(os.listdir(p))
        if 'cl.exe' in files_on_path:
            pass
        elif 'sh.exe' in files_on_path:
            cmake_cmd += ['-G "MSYS Makefiles"']
        elif 'gcc.exe' in files_on_path:
            cmake_cmd += ['-G "MinGW Makefiles"']
        cmake_cmd = ' '.join(cmake_cmd)

def install_proj(args):
    if not os.path.exists(args.build_dir):
        os.mkdir(args.build_dir)
    elif args.replace:
        shutil.rmtree(args.build_dir)
        os.mkdir(args.build_dir)
        
    root_dir = os.path.split(__file__)[0]
    makefile = os.path.join(args.build_dir, 'Makefile')

    if not os.path.exists(makefile):
        cmake_cmd = ['cmake']
        if args.prefix:
            cmake_cmd += ['-DCMAKE_INSTALL_PREFIX=' + absexpanduser(args.prefix)]
        if not args.no_dbc:
            cmake_cmd += ['-DHelloWorld_ENABLE_DBC:BOOL=ON']
        else:
            cmake_cmd += ['-DHelloWorld_ENABLE_DBC:BOOL=OFF']
        if not args.no_mpi:
            cmake_cmd += ['-DHelloWorld_ENABLE_MPI:BOOL=ON']
        else:
            cmake_cmd += ['-DHelloWorld_ENABLE_MPI:BOOL=OFF']
        if args.debug:
            cmake_cmd += ['-DCMAKE_BUILD_TYPE:STRING=Debug']
        cmake_cmd += [os.path.abspath(root_dir)]
        check_windows_cmake(cmake_cmd)
        rtn = subprocess.check_call(cmake_cmd, cwd=args.build_dir, 
                                    shell=(os.name=='nt'))

    make_cmd = ['make']
    if args.threads:
        make_cmd += ['-j' + str(args.threads)]
    rtn = subprocess.check_call(make_cmd, cwd=args.build_dir, shell=(os.name=='nt'))

    if args.test:
        make_cmd = ['make', 'test']
        rtn = subprocess.check_call(make_cmd, cwd=args.build_dir, shell=(os.name=='nt'))
    
    if not args.no_install:
        make_cmd = ['make', 'install']
        rtn = subprocess.check_call(make_cmd, cwd=args.build_dir, shell=(os.name=='nt'))

def main():
    localdir = absexpanduser('~/.local')

    description = "An installation helper script."
    parser = ap.ArgumentParser(description=description)

    build_dir = 'where to place the build directory'
    parser.add_argument('--build_dir', help=build_dir, default='build')

    replace = 'whether or not to remove the build directory if it exists'
    parser.add_argument('--replace', action='store_true', help=replace)

    threads = "the number of threads to use in the make step"
    parser.add_argument('-j', '--threads', type=int, help=threads)

    prefix = "the relative path to the installation directory"
    parser.add_argument('--prefix', help=prefix, default=localdir)

    dbc = "disable design by contract"
    parser.add_argument('--no-dbc', action='store_true', help=dbc)

    mpi = "disable mpi"
    parser.add_argument('--no-mpi', action='store_true', help=mpi)

    debug = "build in debug mode"
    parser.add_argument('--debug', action='store_true', help=debug)

    test = "run tests after building"
    parser.add_argument('--test', action='store_true', help=test)

    install = "don't install after building"
    parser.add_argument('--no-install', action='store_true', help=install)

    install_proj(parser.parse_args())

if __name__ == "__main__":
    main()
