import lazyLoading from './lazyLoading'

export default {
  name: 'Tutorials',
  path: '/tutorials',
  component: lazyLoading('tutorials/Tutorials'),
  meta: {
    default: true,
    title: 'menu.tutorials',
    iconClass: 'vuestic-icon vuestic-icon-video'
  }
}
